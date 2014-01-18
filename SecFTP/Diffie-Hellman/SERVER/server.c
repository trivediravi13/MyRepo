/*****************************************************************************
 *** Program explaining the client-server model                            ***
 *** This is the server program for Diffie-Hellman Key Exchange Protocol   ***
 *** developed by Ashok Kumar Das, CSE Department, IIT Kharagpur           ***
 ***                                                                       ***
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>

/* Global constants */
#define SERVICE_PORT 13108
#define Q_SIZE 5
#define MAX_LEN 1024

#define STACK_SIZE 10000
#define NOT_EXIST 0xFFFF;
#define LARGE 99
#define MAX_ITERATION 10  // Max tests in Miller-Robin Primality Test.
#define div /
#define mod %
#define and &&
#define true 1
#define false 0


#define DEFAULT_SERVER "127.0.0.1"

#define PUBKEY 10  /* Public key */
#define ACK 20     /* Acknowledgement msg */
#define ENCMSG 30  /* Encrypted msg */
#define DCRMSG 40  /* Decrypted message */


/* Define the header of a message structure */
typedef struct {
 int opcode;
 int src_addr;
 int dest_addr;
 } Hdr;

/* Define the body of a message */
typedef struct {
 Hdr hdr;
 char buf[MAX_LEN];
 long int dummy1; /* contains the public element q */ 
 long int dummy2; /* contains the primitive element alpha */
 long int dummy3; /* contains the computed public key value Y */
 char plaintext[MAX_LEN];
 char ciphertext[MAX_LEN];
} Msg;


typedef struct{
	int top;
	char c[STACK_SIZE];
} stack;

typedef short boolean;


long int mul_inverse=0;
long int gcd_value;
stack s;
int print_flag=0;
int print_flag1=0;



/* Function prototypes */
int startServer ( );
void serverLoop ( int );
void Talk_to_client ( int );
void KeyGeneration(long int *q, long int *alpha, long int *private_key, long int *public_key);
char *EncryptionAlgorithm(char *M, long int secret_key);
char *DecryptionAlgorithm(char *C, long int secret_key);


boolean verify_prime(long int p);
long int gcd(long int a, long int b);
void extended_euclid(long int A1, long int A2, long int A3, long int B1, long int B2,long int B3);
long int ModPower(long int x, long int e, long int n);
boolean MillerRobinTest(long int n, int iteration);
void decimal_to_binary(long int n, char str[]);
void reverse_string(char x[]);
long int modulo ( long int x, long int n );
long int primitive_root ( long int q);

/* Start the server: socket(), bind() and listen() */
int startServer ()
{
   int sfd;                    /* for listening to port PORT_NUMBER */
   struct sockaddr_in saddr;   /* address of server */
   int status;

   /* Request for a socket descriptor */
   sfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sfd == -1) {
      fprintf(stderr, "*** Server error: unable to get socket descriptor\n");
      exit(1);
   }

   /* Set the fields of server's internet address structure */
   saddr.sin_family = AF_INET;            /* Default value for most applications */
   saddr.sin_port = htons(SERVICE_PORT);  /* Service port in network byte order */
   saddr.sin_addr.s_addr = INADDR_ANY;    /* Server's local address: 0.0.0.0 (htons not necessary) */
   bzero(&(saddr.sin_zero),8);            /* zero the rest of the structure */

   /* Bind the socket to SERVICE_PORT for listening */
   status = bind(sfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr));
   if (status == -1) {
      fprintf(stderr, "*** Server error: unable to bind to port %d\n", SERVICE_PORT);
      exit(2);
   }

   /* Now listen to the service port */
   status = listen(sfd,Q_SIZE);
   if (status == -1) {
      fprintf(stderr, "*** Server error: unable to listen\n");
      exit(3);
   }

   fprintf(stderr, "+++ Server successfully started, listening to port %hd\n", SERVICE_PORT);
   return sfd;
}



/* Accept connections from clients, spawn a child process for each request */
void serverLoop ( int sfd )
{
   int cfd;                    /* for communication with clients */
   struct sockaddr_in caddr;   /* address of client */
   int size;

    while (1) {
      /* accept connection from clients */
      cfd = accept(sfd, (struct sockaddr *)&caddr, &size);
      if (cfd == -1) {
         fprintf(stderr, "*** Server error: unable to accept request\n");
         continue;
      }
      fprintf(stderr, "**** Connected with %s\n", inet_ntoa(caddr.sin_addr));

 /* fork a child to process request from client */
      if (!fork()) {
         Talk_to_client (cfd);
         fprintf(stderr, "**** Closed connection with %s\n", inet_ntoa(caddr.sin_addr));
         close(cfd);
         exit(0);
      }

      /* parent (server) does not talk with clients */
      close(cfd);

      /* parent waits for termination of child processes */
      while (waitpid(-1,NULL,WNOHANG) > 0);

     
   }
   
}

/* Interaction of the child process with the client */
void Talk_to_client ( int cfd )
{
   char buffer[MAX_LEN];
   int nbytes, status;
   int src_addr, dest_addr;
   int period;
   int i = 0;
   Msg send_msg;
   Msg recv_msg;
   char *plaintext, *ciphertext;
   long int q, alpha, secret_key, public_key, private_key;
   long int X_B, Y_A, Y_B;
   int flag;

   dest_addr = inet_addr("DEFAULT_SERVER");
   src_addr = inet_addr("192.168.1.245");
   
     
   /* Wait for responses from the clent (Alice, User A) */
   while ( 1 ) {

   /* receive messages from server */
   nbytes = recv(cfd, &recv_msg, sizeof(Msg), 0);
   if (nbytes == -1) {
      fprintf(stderr, "*** Client error: unable to receive\n");
      
   }
   printf("%s\n", recv_msg.buf);
   flag = 1;   
   switch ( recv_msg.hdr.opcode ) {
    
   case PUBKEY : /* Public key */
                printf("Message:: PUBKEY received from source (%d)\n", 
                            recv_msg.buf, recv_msg.hdr.src_addr); 

               /* Compute the secret shared key based on public key received from Bob (User B) */
                q =   recv_msg.dummy1;
                alpha = recv_msg.dummy2;
                Y_A = recv_msg.dummy3;
               printf("Received public values from Alice are q = %ld, alpha = %ld, Y_A = %ld\n\r", 
                       q, alpha, Y_A);
               
               /* Select a private key X_B < q */
               private_key = rand() % q;
               X_B = private_key;
               printf("Private key for Bob (User B) is %ld\n\r", X_B);              
 
              /* Compute the public key Y_B */
               public_key = ModPower(alpha, X_B, q);
               Y_B = public_key;
               printf("Public key for Bob (User B) is %ld\n\r", Y_B); 

               /* Send the public key to Alice */
   		printf("Sending the public key to Alice (User A)\n");          
   		send_msg.hdr.opcode = PUBKEY;
   		send_msg.hdr.src_addr = src_addr;
   		send_msg.hdr.dest_addr = dest_addr;
   		strcpy(send_msg.buf,"Public Key from Bob (User B)\n");
                
   		/* send the public key to Alice */
   		send_msg.dummy1 = q;  /* q */
   		send_msg.dummy2 = alpha; /* alpha */
   		send_msg.dummy3 = Y_B;  /* value of public key */
	        /* send the user's response to the server */
   		status = send(cfd, &send_msg, sizeof(Msg), 0);
   		if (status == -1) {
      			fprintf(stderr, "*** Server error: unable to send\n");
      			return;
    		}              

               /* Now compute the secret key shared between Alice and Bob */
               secret_key = ModPower(Y_A, X_B, q);             
               printf("Computed secret key between Alice and Bob (by User B, Bob ) is %ld\n\r", secret_key); 
               /* Send an acknowledgement to Alice that the secret key is computed */       
                send_msg.hdr.opcode = ACK; 
                send_msg.hdr.src_addr = src_addr;
                send_msg.hdr.dest_addr = dest_addr;
                strcpy(send_msg.buf,"Acknowledgement Message from Bob (User B): secret key computed...\n");
                
                break;      
                               
 
   

    case ACK : /* Acknowledgement msg */
               printf("Message:: %s received from source (%d)\n", recv_msg.buf, 
                          recv_msg.hdr.src_addr);
               flag = 0;
               
               break;

   case ENCMSG : /* Encrypted msg */
              printf("Message:: with opcode %d (ENCMSG) received from source (%d)\n", recv_msg.hdr.opcode, recv_msg.hdr.src_addr);
              sprintf(buffer, "Ciphertext received\n", src_addr); 
              send_msg.hdr.opcode = DCRMSG; /* Decrypted message */
              send_msg.hdr.src_addr = src_addr;
              strcpy(send_msg.buf, buffer);
              /* decrypt the ciphertext */
               strcpy(ciphertext, recv_msg.ciphertext);
               printf("Ciphertext received from server :: %s\n", ciphertext);
               strcpy(plaintext, DecryptionAlgorithm(ciphertext, secret_key));
               printf("Recovered plaintext is by the client :: %s\n", plaintext);
               strcpy(send_msg.plaintext, plaintext);            
              
              break;

   case DCRMSG : /* Decrypted message */
             printf("Mssage:: %s received from source (%d)\n", recv_msg.buf, 
             recv_msg.hdr.src_addr);
             strcpy(plaintext, recv_msg.plaintext);
             printf("Recovered plaintext message by the server:: %s \n", plaintext);
             flag = 0;
             break;

   default: 
           printf("Message %s received with opcode: %d\n", recv_msg.buf, 
           recv_msg.hdr.opcode);
           exit(0);

   }
   
   if (flag == 0 ) exit(0);
   
   if (flag != 0 ) {
   /* send the user's response to the server */
   status = send(cfd, &send_msg, sizeof(Msg), 0);
   if (status == -1) {
      fprintf(stderr, "*** Client error: unable to send\n");
      return;
    }
   }
  
  }
}


/*Computing gcd of two integers */
long int gcd(long int a, long int b)
{
	long int r;

	if(a<0) a= -a;
	if(b<0) b= -b;

	if(b==0)
	  return a;

	r= a mod b;

	// exhange r and b, initialize a=b and b=r;
	
	a=b;
	b=r;

	return gcd(a,b);

}


/* Euclid's Extended GCD algorithm to compute the modular inverse of an element */
void extended_euclid(long int A1, long int A2, long int A3, long int B1, long int B2,long int B3)
{
	long int Q;
	long int T1,T2,T3;

	if(B3==0){
		  gcd_value= A3;
		  mul_inverse= NOT_EXIST;
		  return;
	}

	if(B3==1){
		  gcd_value= B3;
		  mul_inverse= B2;
		  return;
	}

	Q=(int)(A3/B3);

	T1=A1-Q*B1;
	T2=A2-Q*B2;
	T3=A3-Q*B3;

	A1=B1;
	A2=B2;
	A3=B3;

	B1=T1;
	B2=T2;
	B3=T3;

	extended_euclid(A1,A2,A3,B1,B2,B3);

}


/* Selecting a prime using the Miller-Robin primality test algorithm */ 
boolean MillerRobinTest(long int n, int iteration)
{
	// n is the given integer and k is the given desired
	// number of iterations in this primality test algorithm.
	// Return true if all the iterations test passed to give
	// the higher confidence that n is a prime, otherwise
	// return false if n is composite.

	long int m, t;
        int i,j;
	long int a, u;
        int flag;

         if(n mod 2 == 0)
		 return false;  // n is composite.

	 m=(n-1) div 2;
	 t=1;

	 while( m mod 2 == 0)  // repeat until m is even
	 {
		 m= m div 2;
		 t=t+1;
       	}
     
      for (j=0; j < iteration; j++) {  // Repeat the test for MAX_ITERATION times
         flag = 0;
         srand((unsigned int) time(NULL));
         a = random() mod n + 1;  // select a in {1,2,......,n}
         u = ModPower(a,m,n);
         if (u == 1 || u == n - 1) flag = 1;     

	 for(i=0;i<t;i++) 
	 {
		 
                 if(u == n - 1)  flag = 1;
		  //return true; //n is prime
                 u = (u * u) mod n;
                 
	 }
         if ( flag == 0 ) return false; // n is composite

     }

	 return true;  // n is prime.
}


/* Finding a primitive root of prime n */
long int primitive_root ( long int n)
{
   long int r, phi_n;
   long int *pw;
   int i, j, flag;

   while ( 1 ) {
      srand((unsigned int) time(NULL));
      r = random() % n;
      if ( gcd ( r, n ) != 1) continue;

      /* compute powers of r modulo n */
      phi_n = n - 1; /* Since n is prime */
      pw = (long int *) malloc (sizeof(long int) * (phi_n + 1) );
      if ( pw == NULL) {
          printf ("Error in allocating space....\n");
          exit(0);
      }
      flag = 0;
      pw[0] = r;
      for ( i = 1; i< phi_n; i++ ) {
        pw[i] = modulo ( pw[i-1] * r, n);
        /* check for repeatations */
        for ( j = 0; j < i; j++ ) {
          if ( pw [i] == pw[j] ) {
            printf("%ld is not a primitive root of %ld\n", r, n);
            flag = 1;
            break;
           }
        }
      }
        if ( flag ) continue;
        if ( flag == 0 ) {
          if (pw[i-1] == 1) 
           return r;
          else 
           continue;
        }
    } /* end while */
       

}


//KEY GENERATION ALGORITHM IN DIFFIE-HELLMAN KEY EXCHANGE PROTOCOL
void KeyGeneration(long int *q, long int *alpha, long int *private_key, long int *public_key)
{
	
        long int p;
	if(print_flag1)
		printf("\n selecting q->\n\r");

	
        
	while(1)
	{
               srand((unsigned int) time(NULL));
               p = random() % LARGE;
               /* test for even number */
               if ( p & 0x01 == 0 ) continue;

               /* Trivial divisibility test by primes 3, 5, 7, 11, 13, 17, 19 */
               if ( (p % 3 == 0 ) || (p % 5 == 0) || (p % 7 == 0) || (p % 11 == 0 )
                    || (p % 13 == 0) || ( p % 17 == 0) || ( p% 19 == 0) )
               continue;

               if( MillerRobinTest(p, MAX_ITERATION) )
		break;
		
	}

    *q = p;
    if (verify_prime(p) )
      printf( "q = %ld is prime\n", *q);
     else {
      printf("q = %ld is composite\n", *q);
      exit(0);
     }
     
     /* Select a primitive root of q */
     *alpha = primitive_root( p );
          
     /* Select a private key  < q  randomly */
     *private_key = rand() % p;

    /* Compute the public key */
    *public_key = ModPower(*alpha, *private_key, *q);

} 


boolean verify_prime(long int p)
{
long int d;
// Test for p;
for(d = 2; d <= (long int) sqrt(p); d++ )
  if ( p % d == 0 ) return false;
return true;
}


// Encryption Algorithm(E)
char *EncryptionAlgorithm(char  *M, long int secret_key)
{
	
}

// Decryption Algorithm(D)
char *DecryptionAlgorithm(char *C, long int secret_key)
{
	
}

/*Convert decimal to binary format */
void decimal_to_binary(long int n, char str[])
{
	// n is the given decimal integer.
	// Purpose is to find the binary conversion
	// of n.
        // Initialise the stack.
	
	 int r;
	 s.top=0;
	
	while(n != 0)

	{
		r= n mod 2;
		s.top++;
		if(s.top >= STACK_SIZE)
		{
			printf("\nstack overflown!\n");
			return;
		}
		s.c[s.top]= r + 48;
		if(print_flag)
		 printf("\n s.c[%d]= %c\n",s.top,s.c[s.top]);
		n=n div 2;

	}

	while(s.top)
	{
          *str++=s.c[s.top--];
	}
	*str='\0';
return;
}


// Algorithm: reverse a string.
void reverse_string(char x[])
{
 int n=strlen(x)-1;
 int i=0;
 char temp[STACK_SIZE];

 for(i=0;i<=n;i++)
	 temp[i]= x[n-i];


 for(i=0;i<=n;i++)
	 x[i]=temp[i];
}

/* modulo operation */
long int modulo ( long int x, long int n )
{
if ( x >= 0 ) 
  x = x % n;
 
 while ( x < 0 ) {
   x = - x;
   x = (( n - 1) * ( x % n )) % n;
 }
 return x;
}

/* Algorithm: Modular Power: x^e(mod n) using 
   the repeated square-and-multiply algorithm */
long int ModPower(long int x, long int e, long int n)
{
	// To calculate y:=x^e(mod n).
        //long y;
        long int y;
	long int t;
        int i;
	int BitLength_e;
	char b[STACK_SIZE];

        //printf("e(decimal) = %ld\n",e);
	decimal_to_binary(e,b);
	if(print_flag)
	 printf("b = %s\n", b);
	BitLength_e = strlen(b);
        
	y = x;

	reverse_string(b);

	for(i = BitLength_e - 2; i >= 0 ; i--)
	{
		if(print_flag)
		 printf("\nb[%d]=%c", i, b[i]);
		if(b[i] == '0')
			t = 1;
		else t = x;
                y = y * y;
                y = modulo (y, n);

		y = y*t;
                y = modulo (y, n);
	}

        
	return y;
        
} 

int main ()
{
   int sfd;

   printf("******* This is the server side demo for implementing Diffie-Hellman Key Exchange Protocol *****\n\n");
   sfd = startServer();

   
   serverLoop(sfd);
}
/*** End of server.c ***/


#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>


/************************************************/
/*		Global Data                    */ 
/***********************************************/

const char *kUserDataFile = "ftppasswd";
#define kUserNameSize 8
#define kPasswdSize 10
#define kMaxFileNameSize 100


const unsigned int SERVICE_PORT = 13108;
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


#define DEFAULT_SERVER "192.168.1.241"

/* Opcodes */
#define PUBKEY 10  /* Public key */
#define ACK 20     /* Acknowledgement msg */
#define ENCMSG 100  /* Encrypted msg */
#define DCRMSG 110  /* Decrypted message */
#define LOGINREQ 30 /* login request */
#define LOGINREP 40
#define LOGINFAILED 90
#define REQSERV 50
#define REQCOM 60
#define DISCONNECT 70 
#define LOGINSUCCESSFUL 80


/* Define the header of a message structure */
typedef struct {
 int opcode;
 } Hdr;

typedef struct {
 char UID[kUserNameSize+1];
 char PWD[kPasswdSize+1];
 }LoginReq;

typedef struct {
 int LoginStatus;

 }LoginResp;

/* Diffie-Hellman public key */
typedef struct {
long q; /* large prime number */
long g; /* a primitive root of q */
long Y ; /* public key, Y = g x (mod q), x is private key */
} DHPubKey;

 typedef struct {
 char FileName[kMaxFileNameSize+1];

}RecvFileReq;

 typedef struct {

  char FData[MAX_LEN+1];
 }FileData;

 typedef union {
 LoginReq uLoginReq;
 LoginResp uLoginResp;
 DHPubKey uDHPubKey;
 RecvFileReq uRecvFileReq;
 FileData uFileData;	
 
 }MsgType;

/* Define the body of a message */
typedef struct {
 Hdr hdr;
 MsgType MsgPayload;
 
} Msg;

typedef struct{
	int top;
	char c[STACK_SIZE];
} stack;

typedef short boolean;

static boolean AuthStatus = false;
static long int KEY = -1;
long int mul_inverse=0;
long int gcd_value;
stack s;
int print_flag=0;
int print_flag1=0;


void Talk_to_client (int);
int UserAuthentication(char *, char *);
void KeyGeneration(long int *q, long int *alpha, long int *private_key, long int *public_key);
void EncryptionAlgorithm(char *M, long int secret_key, char*);
void DecryptionAlgorithm(char *M, long int secret_key, char*);
void SendFileToClient(int, char*);

boolean verify_prime(long int p);
long int gcd(long int a, long int b);
void extended_euclid(long int A1, long int A2, long int A3, long int B1, long int B2,long int B3);
long int ModPower(long int x, long int e, long int n);
boolean MillerRobinTest(long int n, int iteration);
void decimal_to_binary(long int n, char str[]);
void reverse_string(char x[]);
long int modulo ( long int x, long int n );
long int primitive_root ( long int q);

char gindex[97];
int encodebyASCII(char ch)
{
  int alpha=(int)ch;
  if(alpha==10) return 0;
  return (alpha-31);
}

//Decoding an int to char
char decodebyASCII(int i)
{
  return gindex[i];
}

int CalculateXOR(char *iData)
{
	/* Generate XOR of paasword */

	int tXor = 0, tIT = 0;

	tXor = atoi(&iData[0]);
	
	for (; tIT <= kPasswdSize/2; tIT++ )
		tXor ^= atoi(&iData[tIT]);

	return tXor;

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


void EncryptionAlgorithm(char *M,long int secret_key, char *cipher)
{
	 long int enc;
	 int iter;
	 printf("\nStarted Encryption\n");
	 for(iter=0;iter<strlen(M);iter++)
	 {
	     
	     enc=(int)encodebyASCII(M[iter]);
	     enc=(enc+secret_key)%97;	 
	     cipher[iter]=decodebyASCII(enc);
	 }

	

}

void DecryptionAlgorithm(char *M,long int secret_key, char *plaintext)
{
 long int dec;

 int iter;
 printf("\nStarted Decryption");
 for(iter=0;iter<strlen(M);iter++)
 {
    
     dec=(int)encodebyASCII(M[iter]);
     dec=(dec-secret_key)%97;
     if(dec<0)
        dec+=97;
    
     plaintext[iter]=decodebyASCII(dec);

 }


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
      //fprintf(stderr, "*** Server error: unable to bind to port %d\n", SERVICE_PORT);
      perror(" Socket Error : ");
      exit(2);
   }

   /* Now listen to the service port */
   status = listen(sfd,Q_SIZE);
   if (status == -1) {
      fprintf(stderr, "*** Server error: unable to listen\n");
      exit(3);
   }

   fprintf(stderr, "+++ Server successfully started, listening to port %d\n", SERVICE_PORT);
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
   int period;
   int i = 0, flag = 0;
   int tAuthStatus = 3;
   long int q, alpha, secret_key, public_key, private_key;
   long int X_B, Y_A, Y_B;
   Msg *send_msg;
   Msg *recv_msg;


   
     
   /* Wait for responses from the clent (Alice, User A) */
   while ( 1 ) {

	send_msg = (Msg*)malloc(sizeof(Msg));
	recv_msg = (Msg*)malloc(sizeof(Msg));
   /* receive messages from server */
   nbytes = recv(cfd, recv_msg, sizeof(Msg), 0);


   if (nbytes == -1) {
      fprintf(stderr, "*** Client error: unable to receive\n");
      
   }

   flag = 1;   
   switch ( recv_msg->hdr.opcode ) {
    
   case LOGINREQ :
	
         
	 tAuthStatus = UserAuthentication(recv_msg->MsgPayload.uLoginReq.UID, recv_msg->MsgPayload.uLoginReq.PWD);

        if(0 == tAuthStatus ){
		printf(" Authentication Successful...\n");
                send_msg->hdr.opcode = LOGINREP;
	        send_msg->MsgPayload.uLoginResp.LoginStatus = LOGINSUCCESSFUL;
		AuthStatus = true;
	}else if(-1 == tAuthStatus ){
		printf(" User authentication failed... Invalid user Name\n");
		send_msg->hdr.opcode = LOGINREP;
	        send_msg->MsgPayload.uLoginResp.LoginStatus = LOGINFAILED;
		AuthStatus = false;
	}else if( -2 == tAuthStatus ){
		printf("User authentication failed... Password does not match\n");
		send_msg->hdr.opcode = LOGINREP;
	        send_msg->MsgPayload.uLoginResp.LoginStatus = LOGINFAILED;
		AuthStatus = false;
        }
	   printf("Message received with opcode: %d\n",recv_msg->hdr.opcode);
	   printf("received userid : %s\n", recv_msg->MsgPayload.uLoginReq.UID);
	   printf("received userid : %s\n", recv_msg->MsgPayload.uLoginReq.PWD);

	if (flag != 0 ) {
   		/* send the user's response to the server */
   		status = send(cfd, send_msg, sizeof(Msg), 0);
   		if (status == -1) {
      			fprintf(stderr, "*** Client error: unable to send\n");
      			return;
    		}
   	}


	   break;

   case PUBKEY : /* Public key */

	    if ( AuthStatus ) {

               /* Compute the secret shared key based on public key received from Bob (User B) */
                q =   recv_msg->MsgPayload.uDHPubKey.q;
                alpha = recv_msg->MsgPayload.uDHPubKey.g;
                Y_A = recv_msg->MsgPayload.uDHPubKey.Y;
               printf("Received public values from client are q = %ld, alpha = %ld, Y_A = %ld\n\r", 
                       q, alpha, Y_A);
               
               /* Select a private key X_B < q */
               private_key = rand() % q;
               X_B = private_key;
               printf("Private key for server is %ld\n\r", X_B);              
 
              /* Compute the public key Y_B */
               public_key = ModPower(alpha, X_B, q);
               Y_B = public_key;
               printf("Public key for server is %ld\n\r", Y_B); 

               /* Send the public key to Alice */
   		printf("Sending the public key to client\n");          
   		send_msg->hdr.opcode = PUBKEY;
                
   		/* send the public key to Alice */
   		send_msg->MsgPayload.uDHPubKey.q = q;  /* q */
   		send_msg->MsgPayload.uDHPubKey.g = alpha; /* alpha */
   		send_msg->MsgPayload.uDHPubKey.Y = Y_B;  /* value of public key */
	        /* send the user's response to the server */
   		status = send(cfd, send_msg, sizeof(Msg), 0);
   		if (status == -1) {
      			fprintf(stderr, "*** Server error: unable to send\n");
      			return;
    		}              

               /* Now compute the secret key shared between Alice and Bob */
               secret_key = ModPower(Y_A, X_B, q); 
	       KEY = secret_key;
	        printf("Computed secret shared key by server is %ld\n\r", secret_key);            
	    }else {
		
		printf(" Login falied.. Session key exchange not allowed \n");
	
	    }
                break;      
                               
  case REQSERV :
		
		if ( true == AuthStatus && KEY != -1 ) {
			printf ( " File to be sent : %s\n", recv_msg->MsgPayload.uRecvFileReq.FileName);

			SendFileToClient(cfd, recv_msg->MsgPayload.uRecvFileReq.FileName);	

			/* Send request completion */
			send_msg->hdr.opcode = REQCOM;
			status = send(cfd, send_msg, sizeof(Msg), 0);
	   		if (status == -1) {
	      			fprintf(stderr, "*** Server error: unable to send\n");
	      			return;
	    		} 
		}
		break;

   default: 
           printf("Message received with opcode: %d\n",recv_msg->hdr.opcode);
	   exit(0);

   }

    free(recv_msg);
    free(send_msg);
  }
}

void SendFileToClient(int iClientFd, char *iFileName )

{

 Msg *send_msg;
 int len = 0, status = 0;
 char* buf;
	FILE *fp = fopen(iFileName, "r");

	while(!feof(fp)){

		send_msg = (Msg*)malloc(sizeof(Msg));
		buf = (char*)malloc(MAX_LEN*sizeof(char));
		
		len=fread(buf,sizeof(char),MAX_LEN,fp);
	
		char* ciphertext = (char*)malloc(MAX_LEN*sizeof(char));
		EncryptionAlgorithm(buf, KEY, ciphertext);
		printf("encrypted cipher : %s\n", ciphertext);
		snprintf(send_msg->MsgPayload.uFileData.FData,MAX_LEN+1,"%s", ciphertext);	
		//send_msg->MsgPayload.uFileData.FData[strlen(send_msg->MsgPayload.uFileData.FData)+1]='\0';
		send_msg->hdr.opcode = ENCMSG;
		printf(" Sending message ... %d\n", send_msg->hdr.opcode);
		status = send(iClientFd, send_msg, sizeof(Msg), 0);
   		if (status == -1) {
      			fprintf(stderr, "*** Server error: unable to send\n");
      			return;
    		} 

		free(send_msg);
		free(buf);
		free(ciphertext);
	}

			
		fclose(fp);	

}

void NewUserRegistration(void)
{

	char tUID[kUserNameSize+1], tPWD[kPasswdSize+1];

	char *tMaskPwd, *tCharSalt; 
	tMaskPwd= (char*)malloc(10*sizeof(char));
	tCharSalt = (char*)malloc(10*sizeof(char));
	int tSalt = 0, tIT = 0;
	int tXor = 0;
	printf(" New User Registration\n");
	printf(" Enter user name not exceeding 8 characters...\n");
	size_t ret = scanf("%8s",&tUID);
	printf(" Enter password not exceeding 10 characters...\n");
	printf(" New passwd: ");

	struct termios t_old, t_new;

	tcgetattr(STDIN_FILENO, &t_old);
	t_new = t_old;
	t_new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

	scanf("%10s",&tPWD);
	
        tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
	
	printf("Entered passwd : %s\n", &tPWD);


	tXor = CalculateXOR(&tPWD[0]);
	
	/* Generate random salt value */	
	
	printf("Generating salt value..\n");

	int RanFd = open("/dev/random",O_RDONLY);

	read(RanFd, &tSalt, sizeof tSalt);

	printf("Generated Salt value : %u\n", tSalt); 

	/* Mask entered password */

	tXor = tXor ^ tSalt;

	/* Create User info string to be entered in a file */

	sprintf(tMaskPwd, "%u", tXor);
	sprintf(tCharSalt,"%u",tSalt);
	printf("Masked password : %s\n", tMaskPwd);

	char *tUInfo = (char*)malloc(40*sizeof(char));

	printf("Accepted UID : %s\n",&tUID);
	strcpy(tUInfo, tUID);
	strcat(tUInfo, "#");
	strcat(tUInfo, tCharSalt);
	strcat(tUInfo, "#");
	strcat(tUInfo, tMaskPwd);
	strcat(tUInfo, "\0");
	strcat(tUInfo, "\n");
	/* Write String to File */

	FILE *fd = fopen(kUserDataFile, "a+");
	
	fputs(tUInfo, fd);

	fclose(fd);
	printf("User Info String: %s\n", tUInfo);

}

int UserAuthentication(char *iUID, char *iPWD)
{
	FILE *fd = fopen(kUserDataFile, "r");
	char *tUInfo = NULL;
	//char *tUID = (char*)malloc(kUserNameSize*sizeof(char));
	//char *tPWD = (char*)malloc(kPasswdSize*sizeof(char));
	char *tCharSalt = (char*)malloc((kPasswdSize)*sizeof(char));
	char *tMaskPwd= (char*)malloc(kPasswdSize*sizeof(char));
	char *tFilePwd= (char*)malloc(kPasswdSize*sizeof(char));
	ssize_t tLen = 0, tRead = 0;
	int tIT = 0;
	unsigned int tSalt = 0; //(int*)malloc(kPasswdSize*sizeof(int));
	
	//printf("Enter User Name: ");
	//scanf("%8s", tUID);
	while ( (tRead = getline(&tUInfo, &tLen, fd )) != -1 )

	{
		if(strstr(tUInfo,iUID) != NULL)	{

			printf("Retrived String: %s", tUInfo);
		
			//printf("Enter Password: ");
			//scanf("%10s",tPWD);

			for(;tIT<kPasswdSize;tIT++)
				tCharSalt[tIT] = tUInfo[(strlen(iUID)+1)+tIT];


			printf(" Retrived Salt : %s\n", tCharSalt);

			sscanf(tCharSalt, "%u", &tSalt);
			printf("Integer salt : %u\n", tSalt); 
		
			int tXor = CalculateXOR(iPWD) ^ tSalt;
		
			printf(" calulated masked password: %u\n", tXor);
	
			/* retrive masked password from file */

			for(tIT=0;tIT<kPasswdSize;tIT++)
				tFilePwd[tIT] = tUInfo[(strlen(iUID)+strlen(tCharSalt)+2)+tIT];

			printf ( " Retrived masked password: %s\n", tFilePwd);
	
			sprintf(tMaskPwd, "%u", tXor);
		
			if(strcmp(tFilePwd, tMaskPwd) == 0){
				printf(" Password Match....\n");
				return 0;
			}else 
				return -2;
		
		}
	}

	return -1;
}
int main()

{
    int i = 0;	
    gindex[0]='\n';
    for(i=32;i<128;i++)
    {
	gindex[i-31]=i;
    }

	printf ( " Choose option : \n" );
	printf ( " New user registration : 1\n" ) ;
	printf ( " Start Server : 2\n");
	int option = 0;
	printf ( " Enter option here : \n");
	scanf( "%d", &option);

        if ( 1 == option ){

		NewUserRegistration();
		
	}else if ( 2 == option ) {

		int tSockFd = startServer();

		serverLoop(tSockFd);

	}else {

		printf(" Invalid option... \n");
	} 
    	

	

	return 0;
}



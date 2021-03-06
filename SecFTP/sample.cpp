// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "sample.hpp"

// shiporder
// 

const shiporder::orderperson_type& shiporder::
orderperson () const
{
  return this->orderperson_.get ();
}

shiporder::orderperson_type& shiporder::
orderperson ()
{
  return this->orderperson_.get ();
}

void shiporder::
orderperson (const orderperson_type& x)
{
  this->orderperson_.set (x);
}

void shiporder::
orderperson (::std::auto_ptr< orderperson_type > x)
{
  this->orderperson_.set (x);
}

const shiporder::shipto_type& shiporder::
shipto () const
{
  return this->shipto_.get ();
}

shiporder::shipto_type& shiporder::
shipto ()
{
  return this->shipto_.get ();
}

void shiporder::
shipto (const shipto_type& x)
{
  this->shipto_.set (x);
}

void shiporder::
shipto (::std::auto_ptr< shipto_type > x)
{
  this->shipto_.set (x);
}

const shiporder::item_sequence& shiporder::
item () const
{
  return this->item_;
}

shiporder::item_sequence& shiporder::
item ()
{
  return this->item_;
}

void shiporder::
item (const item_sequence& s)
{
  this->item_ = s;
}

const shiporder::orderid_type& shiporder::
orderid () const
{
  return this->orderid_.get ();
}

shiporder::orderid_type& shiporder::
orderid ()
{
  return this->orderid_.get ();
}

void shiporder::
orderid (const orderid_type& x)
{
  this->orderid_.set (x);
}

void shiporder::
orderid (::std::auto_ptr< orderid_type > x)
{
  this->orderid_.set (x);
}


// shipto
// 

const shipto::name_type& shipto::
name () const
{
  return this->name_.get ();
}

shipto::name_type& shipto::
name ()
{
  return this->name_.get ();
}

void shipto::
name (const name_type& x)
{
  this->name_.set (x);
}

void shipto::
name (::std::auto_ptr< name_type > x)
{
  this->name_.set (x);
}

const shipto::address_type& shipto::
address () const
{
  return this->address_.get ();
}

shipto::address_type& shipto::
address ()
{
  return this->address_.get ();
}

void shipto::
address (const address_type& x)
{
  this->address_.set (x);
}

void shipto::
address (::std::auto_ptr< address_type > x)
{
  this->address_.set (x);
}

const shipto::city_type& shipto::
city () const
{
  return this->city_.get ();
}

shipto::city_type& shipto::
city ()
{
  return this->city_.get ();
}

void shipto::
city (const city_type& x)
{
  this->city_.set (x);
}

void shipto::
city (::std::auto_ptr< city_type > x)
{
  this->city_.set (x);
}

const shipto::country_type& shipto::
country () const
{
  return this->country_.get ();
}

shipto::country_type& shipto::
country ()
{
  return this->country_.get ();
}

void shipto::
country (const country_type& x)
{
  this->country_.set (x);
}

void shipto::
country (::std::auto_ptr< country_type > x)
{
  this->country_.set (x);
}


// item
// 

const item::title_type& item::
title () const
{
  return this->title_.get ();
}

item::title_type& item::
title ()
{
  return this->title_.get ();
}

void item::
title (const title_type& x)
{
  this->title_.set (x);
}

void item::
title (::std::auto_ptr< title_type > x)
{
  this->title_.set (x);
}

const item::note_optional& item::
note () const
{
  return this->note_;
}

item::note_optional& item::
note ()
{
  return this->note_;
}

void item::
note (const note_type& x)
{
  this->note_.set (x);
}

void item::
note (const note_optional& x)
{
  this->note_ = x;
}

void item::
note (::std::auto_ptr< note_type > x)
{
  this->note_.set (x);
}

const item::quantity_type& item::
quantity () const
{
  return this->quantity_.get ();
}

item::quantity_type& item::
quantity ()
{
  return this->quantity_.get ();
}

void item::
quantity (const quantity_type& x)
{
  this->quantity_.set (x);
}

const item::price_type& item::
price () const
{
  return this->price_.get ();
}

item::price_type& item::
price ()
{
  return this->price_.get ();
}

void item::
price (const price_type& x)
{
  this->price_.set (x);
}


#include <xsd/cxx/xml/dom/parsing-source.hxx>

// shiporder
//

shiporder::
shiporder (const orderperson_type& orderperson,
           const shipto_type& shipto,
           const orderid_type& orderid)
: ::xml_schema::type (),
  orderperson_ (orderperson, ::xml_schema::flags (), this),
  shipto_ (shipto, ::xml_schema::flags (), this),
  item_ (::xml_schema::flags (), this),
  orderid_ (orderid, ::xml_schema::flags (), this)
{
}

shiporder::
shiporder (const orderperson_type& orderperson,
           ::std::auto_ptr< shipto_type >& shipto,
           const orderid_type& orderid)
: ::xml_schema::type (),
  orderperson_ (orderperson, ::xml_schema::flags (), this),
  shipto_ (shipto, ::xml_schema::flags (), this),
  item_ (::xml_schema::flags (), this),
  orderid_ (orderid, ::xml_schema::flags (), this)
{
}

shiporder::
shiporder (const shiporder& x,
           ::xml_schema::flags f,
           ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  orderperson_ (x.orderperson_, f, this),
  shipto_ (x.shipto_, f, this),
  item_ (x.item_, f, this),
  orderid_ (x.orderid_, f, this)
{
}

shiporder::
shiporder (const ::xercesc::DOMElement& e,
           ::xml_schema::flags f,
           ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  orderperson_ (f, this),
  shipto_ (f, this),
  item_ (f, this),
  orderid_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, true);
    this->parse (p, f);
  }
}

void shiporder::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // orderperson
    //
    if (n.name () == "orderperson" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< orderperson_type > r (
        orderperson_traits::create (i, f, this));

      if (!orderperson_.present ())
      {
        this->orderperson_.set (r);
        continue;
      }
    }

    // shipto
    //
    if (n.name () == "shipto" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< shipto_type > r (
        shipto_traits::create (i, f, this));

      if (!shipto_.present ())
      {
        this->shipto_.set (r);
        continue;
      }
    }

    // item
    //
    if (n.name () == "item" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< item_type > r (
        item_traits::create (i, f, this));

      this->item_.push_back (r);
      continue;
    }

    break;
  }

  if (!orderperson_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "orderperson",
      "");
  }

  if (!shipto_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "shipto",
      "");
  }

  while (p.more_attributes ())
  {
    const ::xercesc::DOMAttr& i (p.next_attribute ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    if (n.name () == "orderid" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< orderid_type > r (
        orderid_traits::create (i, f, this));

      this->orderid_.set (r);
      continue;
    }
  }

  if (!orderid_.present ())
  {
    throw ::xsd::cxx::tree::expected_attribute< char > (
      "orderid",
      "");
  }
}

shiporder* shiporder::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class shiporder (*this, f, c);
}

shiporder::
~shiporder ()
{
}

// shipto
//

shipto::
shipto (const name_type& name,
        const address_type& address,
        const city_type& city,
        const country_type& country)
: ::xml_schema::type (),
  name_ (name, ::xml_schema::flags (), this),
  address_ (address, ::xml_schema::flags (), this),
  city_ (city, ::xml_schema::flags (), this),
  country_ (country, ::xml_schema::flags (), this)
{
}

shipto::
shipto (const shipto& x,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  name_ (x.name_, f, this),
  address_ (x.address_, f, this),
  city_ (x.city_, f, this),
  country_ (x.country_, f, this)
{
}

shipto::
shipto (const ::xercesc::DOMElement& e,
        ::xml_schema::flags f,
        ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  name_ (f, this),
  address_ (f, this),
  city_ (f, this),
  country_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void shipto::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // name
    //
    if (n.name () == "name" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< name_type > r (
        name_traits::create (i, f, this));

      if (!name_.present ())
      {
        this->name_.set (r);
        continue;
      }
    }

    // address
    //
    if (n.name () == "address" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< address_type > r (
        address_traits::create (i, f, this));

      if (!address_.present ())
      {
        this->address_.set (r);
        continue;
      }
    }

    // city
    //
    if (n.name () == "city" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< city_type > r (
        city_traits::create (i, f, this));

      if (!city_.present ())
      {
        this->city_.set (r);
        continue;
      }
    }

    // country
    //
    if (n.name () == "country" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< country_type > r (
        country_traits::create (i, f, this));

      if (!country_.present ())
      {
        this->country_.set (r);
        continue;
      }
    }

    break;
  }

  if (!name_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "name",
      "");
  }

  if (!address_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "address",
      "");
  }

  if (!city_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "city",
      "");
  }

  if (!country_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "country",
      "");
  }
}

shipto* shipto::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class shipto (*this, f, c);
}

shipto::
~shipto ()
{
}

// item
//

item::
item (const title_type& title,
      const quantity_type& quantity,
      const price_type& price)
: ::xml_schema::type (),
  title_ (title, ::xml_schema::flags (), this),
  note_ (::xml_schema::flags (), this),
  quantity_ (quantity, ::xml_schema::flags (), this),
  price_ (price, ::xml_schema::flags (), this)
{
}

item::
item (const item& x,
      ::xml_schema::flags f,
      ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  title_ (x.title_, f, this),
  note_ (x.note_, f, this),
  quantity_ (x.quantity_, f, this),
  price_ (x.price_, f, this)
{
}

item::
item (const ::xercesc::DOMElement& e,
      ::xml_schema::flags f,
      ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  title_ (f, this),
  note_ (f, this),
  quantity_ (f, this),
  price_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void item::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // title
    //
    if (n.name () == "title" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< title_type > r (
        title_traits::create (i, f, this));

      if (!title_.present ())
      {
        this->title_.set (r);
        continue;
      }
    }

    // note
    //
    if (n.name () == "note" && n.namespace_ ().empty ())
    {
      ::std::auto_ptr< note_type > r (
        note_traits::create (i, f, this));

      if (!this->note_)
      {
        this->note_.set (r);
        continue;
      }
    }

    // quantity
    //
    if (n.name () == "quantity" && n.namespace_ ().empty ())
    {
      if (!quantity_.present ())
      {
        this->quantity_.set (quantity_traits::create (i, f, this));
        continue;
      }
    }

    // price
    //
    if (n.name () == "price" && n.namespace_ ().empty ())
    {
      if (!price_.present ())
      {
        this->price_.set (price_traits::create (i, f, this));
        continue;
      }
    }

    break;
  }

  if (!title_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "title",
      "");
  }

  if (!quantity_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "quantity",
      "");
  }

  if (!price_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "price",
      "");
  }
}

item* item::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class item (*this, f, c);
}

item::
~item ()
{
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

::std::auto_ptr< ::shiporder >
shiporder_ (const ::std::string& u,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (const ::std::string& u,
            ::xml_schema::error_handler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (const ::std::string& u,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::shiporder_ (isrc, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            ::xml_schema::error_handler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::shiporder_ (isrc, h, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::shiporder_ (isrc, h, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            const ::std::string& sid,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::shiporder_ (isrc, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            const ::std::string& sid,
            ::xml_schema::error_handler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::shiporder_ (isrc, h, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::std::istream& is,
            const ::std::string& sid,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::shiporder_ (isrc, h, f, p);
}

::std::auto_ptr< ::shiporder >
shiporder_ (::xercesc::InputSource& i,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (::xercesc::InputSource& i,
            ::xml_schema::error_handler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (::xercesc::InputSource& i,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::shiporder > r (
    ::shiporder_ (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::shiporder >
shiporder_ (const ::xercesc::DOMDocument& d,
            ::xml_schema::flags f,
            const ::xml_schema::properties& p)
{
  if (f & ::xml_schema::flags::keep_dom)
  {
    ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > c (
      static_cast< ::xercesc::DOMDocument* > (d.cloneNode (true)));

    ::std::auto_ptr< ::shiporder > r (
      ::shiporder_ (
        c, f | ::xml_schema::flags::own_dom, p));

    return r;
  }

  const ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "shiporder" &&
      n.namespace_ () == "")
  {
    ::std::auto_ptr< ::shiporder > r (
      ::xsd::cxx::tree::traits< ::shiporder, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "shiporder",
    "");
}

::std::auto_ptr< ::shiporder >
shiporder_ (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
            ::xml_schema::flags f,
            const ::xml_schema::properties&)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > c (
    ((f & ::xml_schema::flags::keep_dom) &&
     !(f & ::xml_schema::flags::own_dom))
    ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
    : 0);

  ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
  const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (f & ::xml_schema::flags::keep_dom)
    doc.setUserData (::xml_schema::dom::tree_node_key,
                     (c.get () ? &c : &d),
                     0);

  if (n.name () == "shiporder" &&
      n.namespace_ () == "")
  {
    ::std::auto_ptr< ::shiporder > r (
      ::xsd::cxx::tree::traits< ::shiporder, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "shiporder",
    "");
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

void
shiporder_ (::std::ostream& o,
            const ::shiporder& s,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
shiporder_ (::std::ostream& o,
            const ::shiporder& s,
            ::xml_schema::error_handler& h,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
shiporder_ (::std::ostream& o,
            const ::shiporder& s,
            ::xercesc::DOMErrorHandler& h,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
shiporder_ (::xercesc::XMLFormatTarget& t,
            const ::shiporder& s,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
shiporder_ (::xercesc::XMLFormatTarget& t,
            const ::shiporder& s,
            ::xml_schema::error_handler& h,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
shiporder_ (::xercesc::XMLFormatTarget& t,
            const ::shiporder& s,
            ::xercesc::DOMErrorHandler& h,
            const ::xml_schema::namespace_infomap& m,
            const ::std::string& e,
            ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::shiporder_ (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
shiporder_ (::xercesc::DOMDocument& d,
            const ::shiporder& s,
            ::xml_schema::flags)
{
  ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "shiporder" &&
      n.namespace_ () == "")
  {
    e << s;
  }
  else
  {
    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "shiporder",
      "");
  }
}

::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
shiporder_ (const ::shiporder& s,
            const ::xml_schema::namespace_infomap& m,
            ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::serialize< char > (
      "shiporder",
      "",
      m, f));

  ::shiporder_ (*d, s, f);
  return d;
}

void
operator<< (::xercesc::DOMElement& e, const shiporder& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // orderperson
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "orderperson",
        e));

    s << i.orderperson ();
  }

  // shipto
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "shipto",
        e));

    s << i.shipto ();
  }

  // item
  //
  for (shiporder::item_const_iterator
       b (i.item ().begin ()), n (i.item ().end ());
       b != n; ++b)
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "item",
        e));

    s << *b;
  }

  // orderid
  //
  {
    ::xercesc::DOMAttr& a (
      ::xsd::cxx::xml::dom::create_attribute (
        "orderid",
        e));

    a << i.orderid ();
  }
}

void
operator<< (::xercesc::DOMElement& e, const shipto& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // name
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "name",
        e));

    s << i.name ();
  }

  // address
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "address",
        e));

    s << i.address ();
  }

  // city
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "city",
        e));

    s << i.city ();
  }

  // country
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "country",
        e));

    s << i.country ();
  }
}

void
operator<< (::xercesc::DOMElement& e, const item& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // title
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "title",
        e));

    s << i.title ();
  }

  // note
  //
  if (i.note ())
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "note",
        e));

    s << *i.note ();
  }

  // quantity
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "quantity",
        e));

    s << i.quantity ();
  }

  // price
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "price",
        e));

    s << ::xml_schema::as_decimal(i.price ());
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.


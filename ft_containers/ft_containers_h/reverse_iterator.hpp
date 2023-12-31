#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
	protected: 
		Iter current;
	public:

		typedef Iter											iterator_type;
		typedef typename iterator_traits<Iter>::difference_type	difference_type;
		typedef typename iterator_traits<Iter>::reference		reference;
		typedef typename iterator_traits<Iter>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;

		// constructors
		reverse_iterator() : current() {}
		explicit reverse_iterator(Iter x) : current(x) {}
		template <class Up>
		reverse_iterator(const reverse_iterator<Up>& u) : current(u.base()) {}

		// base
		Iter	base() const {return current;}

		// Member functions
		reference			operator* () const { Iter tmp = current; return *--tmp; }
		pointer				operator->() const { Iter tmp = current; return &(*(--tmp)); }
		reverse_iterator&	operator++() { --current; return *this; }
		reverse_iterator	operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
		reverse_iterator&	operator--() { ++current; return *this; }
		reverse_iterator	operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
		reverse_iterator	operator+ (difference_type n) const;
		reverse_iterator&	operator+=(difference_type n) { current -= n; return *this; }
		reverse_iterator 	operator- (difference_type n) const;
		reverse_iterator&	operator-=(difference_type n) { current += n; return *this; }
		reference			operator[](difference_type n) const { Iter tmp = (current - n); return *--tmp; }
	};
	
	// Member functions
	template <class Iter>
	reverse_iterator<Iter>	ft::reverse_iterator<Iter>::operator+ (difference_type n) const { return reverse_iterator(current - n); }
	template <class Iter>
	reverse_iterator<Iter> 	ft::reverse_iterator<Iter>::operator- (difference_type n) const { return reverse_iterator(current + n); }
	

	// relational operators
	template <class Iter1, class Iter2>
	bool
	operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() == y.base(); }

	template <class Iter1, class Iter2>
	bool
	operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() != y.base(); }

	template <class Iter1, class Iter2>
	bool
	operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() > y.base(); }

	template <class Iter1, class Iter2>
	bool
	operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() >= y.base(); }

	template <class Iter1, class Iter2>
	bool
	operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() < y.base(); }

	template <class Iter1, class Iter2>
	bool
	operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return x.base() <= y.base(); }

	// operator+
	template <class Iter>
	reverse_iterator<Iter>
	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
	{ return reverse_iterator<Iter>(x.base() - n); }

	// operator-
	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{ return y.base() - x.base(); }
}

#endif

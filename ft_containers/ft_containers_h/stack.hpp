#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename _Tp, typename _Container = ft::vector<_Tp> >
	class stack
	{
	public:
		typedef _Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;

	protected:
		container_type c_;

	public:
		//constructor
		explicit stack(const container_type& c = container_type()) : c_(c) {}

		//member functions
		bool empty() const { return c_.empty(); }
		size_type size() const { return c_.size(); }
		value_type& top() { return c_.back(); }
		const value_type& top() const { return c_.back(); }
		void push(const value_type& v) { c_.push_back(v); }
		void pop() { c_.pop_back(); }


		template <class T, class C>
		friend bool operator==(const stack<T, C>& x, const stack<T, C>& y);

		template <class T, class C>
		friend bool operator< (const stack<T, C>& x, const stack<T, C>& y);
	};

	template <class Tp, class Container>
	bool operator==(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return x.c_ == y.c_; }

	template <class Tp, class Container>
	bool operator< (const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return x.c_ < y.c_; }

	template <class Tp, class Container>
	bool operator!=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return !(x == y); }

	template <class Tp, class Container>
	bool operator>(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return y < x; }

	template <class Tp, class Container>
	bool operator>=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return !(x < y); }

	template <class Tp, class Container>
	bool operator<=(const stack<Tp, Container>& x, const stack<Tp, Container>& y)
	{ return !(y < x); }
}

#endif

// RTTI support for -*- C++ -*-
// Copyright (C) 1994-2019 Free Software Foundation, Inc.
//
// This file is part of GCC.
//
// GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file typeinfo
 *  This is a Standard C++ Library header.
 */

#ifndef _TYPEINFO
#define _TYPEINFO

#pragma GCC system_header
#include <syscall.hh>
// RFP added this ifdef
#ifdef EXCEPTIONS_ENABLED
#include <bits/exception.h>
#endif

// RFP added this ifdef
#ifdef USE_HASH_BYTES
#if __cplusplus >= 201103L
#include <bits/hash_bytes.h>
#endif
#endif

#pragma GCC visibility push(default)

extern "C++" {

	namespace __cxxabiv1
	{
		class __class_type_info;
	}

	namespace std
	{
		class type_info
		{
			public:
				virtual ~type_info();

				const char* name() const
				{
					return __name[0] == '*' ? __name + 1 : __name;
				}

				bool before(const type_info& __arg) const ;
				bool operator==(const type_info& __arg) const ;

				bool operator!=(const type_info& __arg) const 
				{ return !operator==(__arg); }

				size_t hash_code() const noexcept
				{
					return reinterpret_cast<size_t>(__name);
				}

				// Return true if this is a pointer type of some kind
				virtual bool __is_pointer_p() const;

				// Return true if this is a function type
				virtual bool __is_function_p() const;

				// Try and catch a thrown type. Store an adjusted pointer to the
				// caught type in THR_OBJ. If THR_TYPE is not a pointer type, then
				// THR_OBJ points to the thrown object. If THR_TYPE is a pointer
				// type, then THR_OBJ is the pointer itself. OUTER indicates the
				// number of outer pointers, and whether they were const
				// qualified.
				virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
						unsigned __outer) const;

				// Internally used during catch matching
				virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
						void **__obj_ptr) const;

			protected:
				const char * const __name;

				explicit type_info(const char *__n): __name(__n) { }

			private:
				/// Assigning type_info is not supported.
				type_info& operator=(const type_info&);
				type_info(const type_info&);
		};
#ifdef EXCEPTIONS_ENABLED
		/**
		 *  @brief  Thrown during incorrect typecasting.
		 *  @ingroup exceptions
		 *
		 *  If you attempt an invalid @c dynamic_cast expression, an instance of
		 *  this class (or something derived from this class) is thrown.  */
		class bad_cast : public exception
		{
			public:
				bad_cast() _GLIBCXX_USE_NOEXCEPT { }

				// This declaration is not useless:
				// http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
				virtual ~bad_cast() _GLIBCXX_USE_NOEXCEPT;

				// See comment in eh_exception.cc.
				virtual const char* what() const _GLIBCXX_USE_NOEXCEPT;
		};

		/**
		 *  @brief Thrown when a NULL pointer in a @c typeid expression is used.
		 *  @ingroup exceptions
		 */
		class bad_typeid : public exception
		{
			public:
				bad_typeid () _GLIBCXX_USE_NOEXCEPT { }

				// This declaration is not useless:
				// http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
				virtual ~bad_typeid() _GLIBCXX_USE_NOEXCEPT;

				// See comment in eh_exception.cc.
				virtual const char* what() const _GLIBCXX_USE_NOEXCEPT;
		};
#endif
	} // namespace std

} // extern "C++"

#pragma GCC visibility pop

#endif

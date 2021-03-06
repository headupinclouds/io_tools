//-----------------------------------------------------------------------------
// Copyright (c) 2015-2017 Benjamin Buch
//
// https://github.com/bebuch/io_tools
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)
//-----------------------------------------------------------------------------
#ifndef _io_tools__time_to_dir_string__hpp_INCLUDED_
#define _io_tools__time_to_dir_string__hpp_INCLUDED_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>


namespace io_tools{


	/// \brief Convert a time_point into a string for directory names
	///
	/// Output format: YYYYMMDD_hhmmss
	template < typename CharT, typename Traits >
	inline std::basic_ostream< CharT, Traits >& time_to_dir_string(
		std::basic_ostream< CharT, Traits >& os,
		std::chrono::system_clock::time_point const& time =
			std::chrono::system_clock::now()
	){
		auto localtime = std::chrono::system_clock::to_time_t(time);
		auto datetime = *std::localtime(&localtime);

		return os
			<< std::fixed << std::setfill('0')
			<< std::setw(4) << 1900 + datetime.tm_year
			<< std::setw(2) << 1 + datetime.tm_mon
			<< std::setw(2) << datetime.tm_mday << "_"
			<< std::setw(2) << datetime.tm_hour
			<< std::setw(2) << datetime.tm_min
			<< std::setw(2) << datetime.tm_sec;
	}


	/// \brief Date and time as basic_string of type CharT
	template <
		typename CharT,
		typename Traits = std::char_traits< CharT >,
		typename Allocator = std::allocator< CharT >
	>
	inline std::basic_string< CharT, Traits, Allocator > time_to_dir_string(
		std::chrono::system_clock::time_point const& time =
			std::chrono::system_clock::now()
	){
		std::basic_ostringstream< CharT, Traits, Allocator > os;

		time_to_dir_string(os, time);

		return os.str();
	}

	/// \brief Date and time as string for directory names
	inline std::string time_to_dir_string(
		std::chrono::system_clock::time_point const& time =
			std::chrono::system_clock::now()
	){
		return time_to_dir_string< char >(time);
	}


}


#endif

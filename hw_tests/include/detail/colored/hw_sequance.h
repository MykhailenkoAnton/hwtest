#pragma once

#include <string>
#include <ostream>

#include <vector>

#include <utility>

#include "hw_item.h"


namespace hwtest
{
namespace colored
{
	template<typename T>
	class ou_sequance
	{
	public:
		template<typename... Args>
		void emplace_back(Args&&... args)
		{
			colored_items.emplace_back(std::forward<Args>(args)...);
		}

		ou_sequance<T>& operator+=(const ou_sequance<T>& lhs)
		{
			this->colored_items.insert(this->colored_items.end(), lhs.colored_items.begin(), lhs.colored_items.end());
			return *this;
		}

		template<typename U>
		friend std::ostream& operator<<(std::ostream& os, const ou_sequance<U>& item);

	private:
		std::vector<ou_item<T>> colored_items;
	};

	template<typename T>
	ou_sequance<T> operator+(ou_sequance<T> lhs, ou_sequance<T> rhs)
	{
		lhs += rhs;
		return lhs;
	}

	template<typename T>
	ou_sequance<T> operator+(ou_sequance<T> lhs, std::string rhs)
	{
		lhs.emplace_back(rhs);
		return lhs;
	}

	template <typename T>
	ou_sequance<T> operator+(std::string lhs, ou_sequance<T>  rhs)
	{
		ou_sequance<T> s;
		s.emplace_back(lhs);
		s += rhs;

		return s;
	}

	template<typename U>
	std::ostream& operator<<(std::ostream& os, const ou_sequance<U>& item)
	{
		for (const auto& elem : item.colored_items)
		{
			os << elem;
		}

		return os;
	}

} // colored
} // hwtest


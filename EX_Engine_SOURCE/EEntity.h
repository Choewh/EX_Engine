#pragma once
#include "CommonInclude.h"
using namespace EX::math;

namespace EX {
	class Entity
	{
	public:
		Entity();
			virtual ~Entity();

			void SetName(const std::wstring& name) { mName = name; }
			std::wstring GetName() { return mName; }
	private:
		std::wstring mName;
	};
}

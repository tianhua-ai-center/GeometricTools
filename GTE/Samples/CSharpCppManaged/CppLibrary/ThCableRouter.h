#pragma once
#include "stdafx.h"
#include "ThCppExport.h"

namespace gte
{
	class THMODULE_EXPORT ThCableRouter
	{
	public:
		std::string Route(const std::string& geojson);
	};
}


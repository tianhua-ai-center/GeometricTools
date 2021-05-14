#pragma once
#include "stdafx.h"

namespace gte
{
	struct ThProtectionContext
	{
		// 消火栓水龙带半径
		double hydrant_hose_length;
		// 消火栓水柱半径
		double hydrant_clearance_radius;
	};

	class ThHydrantEngine
	{
	public:
		void Validate(const std::string& geojson, const ThProtectionContext& context, std::vector<std::string>& result);
	};
}


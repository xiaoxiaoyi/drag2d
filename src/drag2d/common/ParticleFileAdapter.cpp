/*
* Copyright (c) 2012-2013 Guang Zhu http://runnersoft.net
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "ParticleFileAdapter.h"

#include "common/FileNameTools.h"

#include <fstream>

using namespace d2d;

void ParticleFileAdapter::load(const char* filename)
{
	Json::Value value;
	Json::Reader reader;
	std::ifstream fin(filename);
	reader.parse(fin, value);
	fin.close();

	name = value["name"].asString();
	package = value["package"].asString();
	count = value["count"].asInt();
	layer = value["layer"].asInt();
	emission_time = value["emission_time"].asInt();
	min_life = value["min_life"].asInt();
	max_life = value["max_life"].asInt();
	min_hori = value["min_hori"].asInt();
	max_hori = value["max_hori"].asInt();
	min_vert = value["min_vert"].asInt();
	max_vert = value["max_vert"].asInt();
	min_spd = value["min_spd"].asInt();
	max_spd = value["max_spd"].asInt();
	gravity = value["gravity"].asInt();
	inertia = value["inertia"].asInt();
	fadeout_time = value["fadeout_time"].asInt();
	bounce = value["bounce"].asInt();
	additive_blend = value["additive_blend"].asInt();
	start_radius = value["start_radius"].asInt();
	orient_to_movement = value["orient_to_movement"].asBool();
	orient_to_parent = value["orient_to_parent"].asBool();
	
	std::string dir = FilenameTools::getFileDir(filename);
	int i = 0;
	Json::Value childValue = value["components"][i++];
	while (!childValue.isNull()) {
		Child child;
		child.filepath = childValue["filepath"].asString();
		child.filepath = FilenameTools::getAbsolutePath(dir, child.filepath);
		child.name = childValue["name"].asString();
		child.start_scale = childValue["start_scale"].asInt();
		child.end_scale = childValue["end_scale"].asInt();
		child.min_rotate = childValue["min_rotate"].asInt();
		child.max_rotate = childValue["max_rotate"].asInt();
		child.start_z = childValue["start_z"].asInt();
		children.push_back(child);
		childValue = value["components"][i++];
	}
}
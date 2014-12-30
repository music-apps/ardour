/*
    Copyright (C) 2014 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __libardour_scene_change_h__
#define __libardour_scene_change_h__

#include "pbd/stateful.h"

#include "ardour/types.h"

namespace ARDOUR
{

class SceneChange : public PBD::Stateful
{
  public:
	SceneChange ();
	virtual ~SceneChange () {};

	static boost::shared_ptr<SceneChange> factory (const XMLNode&, int version);
	static std::string xml_node_name;

	uint32_t color() const;
	void set_color (uint32_t);
	bool color_out_of_bounds() const { return _color == out_of_bound_color; }
	static const uint32_t out_of_bound_color;
        
	PBD::Signal0<void> ColorChanged;

protected:
	/* derived classes are responsible for serializing & deserializing this value */
	uint32_t _color;

};

} /* namespace */
	

#endif /* __libardour_scene_change_h__ */

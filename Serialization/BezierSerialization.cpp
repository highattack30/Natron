/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <http://www.natron.fr/>,
 * Copyright (C) 2016 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#include "BezierSerialization.h"

#include "Serialization/BezierCPSerialization.h"

SERIALIZATION_NAMESPACE_ENTER

void
BezierSerialization::encode(YAML_NAMESPACE::Emitter& em) const
{
    em << YAML_NAMESPACE::BeginMap;
    RotoDrawableItemSerialization::encode(em);
    if (!_controlPoints.empty()) {
        em << YAML_NAMESPACE::Key << "Shape" << YAML_NAMESPACE::Value;
        em << YAML_NAMESPACE::BeginSeq;
        for (std::list< ControlPoint >::const_iterator it = _controlPoints.begin(); it != _controlPoints.end(); ++it) {
            em << YAML_NAMESPACE::BeginMap;
            em << YAML_NAMESPACE::Key << "Inner" << YAML_NAMESPACE::Value;
            it->innerPoint.encode(em);
            if (it->featherPoint) {
                em << YAML_NAMESPACE::Key << "Feather" << YAML_NAMESPACE::Value;
                it->featherPoint->encode(em);
            }
            em << YAML_NAMESPACE::EndMap;
        }
        em << YAML_NAMESPACE::EndSeq;
    }
    em << YAML_NAMESPACE::Key << "CanClose" << YAML_NAMESPACE::Value << !_isOpenBezier;
    if (!_isOpenBezier) {
        em << YAML_NAMESPACE::Key << "Closed" << YAML_NAMESPACE::Value << _closed;
    }
    em << YAML_NAMESPACE::EndMap;
}

void
BezierSerialization::decode(const YAML_NAMESPACE::Node& node)
{
    RotoDrawableItemSerialization::decode(node);
    if (node["Shape"]) {
        YAML_NAMESPACE::Node shapeNode = node["Shape"];
        for (std::size_t i = 0; i < shapeNode.size(); ++i) {
            ControlPoint c;
            YAML_NAMESPACE::Node pointNode = shapeNode[i];
            if (pointNode["Inner"]) {
                c.innerPoint.decode(pointNode["Inner"]);
            }
            if (pointNode["Feather"]) {
                c.featherPoint.reset(new BezierCPSerialization);
                c.featherPoint->decode(pointNode["Feather"]);
            }
            _controlPoints.push_back(c);
        }
    }
    if (node["Closed"]) {
        _closed = node["Closed"].as<bool>();
    }

    if (node["CanClose"]) {
        _isOpenBezier = !node["CanClose"].as<bool>();
    } else {
        _isOpenBezier = false;
    }
}

SERIALIZATION_NAMESPACE_EXIT
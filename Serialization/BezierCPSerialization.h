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

#ifndef Engine_BezierCPSerialization_h
#define Engine_BezierCPSerialization_h


#include "Serialization/CurveSerialization.h"

SERIALIZATION_NAMESPACE_ENTER;

class BezierCPSerialization
: public SerializationObjectBase
{
public:

    // Animation of the point
    CurveSerialization xCurve, yCurve, leftCurveX, rightCurveX, leftCurveY, rightCurveY;

    // If the point is not animated, this is its static value
    double x,y,leftX,rightX,leftY,rightY;


    BezierCPSerialization()
    : xCurve()
    , yCurve()
    , leftCurveX()
    , rightCurveX()
    , leftCurveY()
    , rightCurveY()
    , x(0)
    , y(0)
    , leftX(0)
    , rightX(0)
    , leftY(0)
    , rightY(0)
    {

    }

    virtual ~BezierCPSerialization()
    {

    }

    virtual void encode(YAML_NAMESPACE::Emitter& em) const OVERRIDE FINAL;

    virtual void decode(const YAML_NAMESPACE::Node& node) OVERRIDE FINAL;
};



SERIALIZATION_NAMESPACE_EXIT;



#endif // Engine_BezierCPSerialization_h

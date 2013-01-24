/*
    libnoisecl - procedural noise generation tool based on OpenCL library
    Copyright (C) 2013  Messenger of death <messengerofdeath@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once


#include <string>
#include "clnoiseerror.h"

namespace CLNoise
{
class ModuleAttribute
{
public:
    enum ATTRIBUTE_TYPE
    {
        INVALID = -1,
        INT     = 0,
        FLOAT   = 1,
    };
    ModuleAttribute() : type ( INVALID ) {};
    explicit ModuleAttribute ( const std::string &name, int val ) : intValue ( val ), floatValue ( -1 ), type ( INT ), attributeName ( name ) {};
    explicit ModuleAttribute ( const std::string &name, float val ) : intValue ( -1 ), floatValue ( val ), type ( FLOAT ), attributeName ( name ) {};

    void setValue ( int val )
    {
        type = INT;
        intValue = val;
    }

    void setValue ( float val )
    {
        type = FLOAT;
        floatValue = val;
    }

    int getInt() const
    {
        if ( type != INT ) THROW ( "Invalid type requested" );
        return intValue;
    }

    float getFloat() const
    {
        if ( type != FLOAT ) THROW ( "Invalid type requested" );
        return floatValue;
    }

    ATTRIBUTE_TYPE getType() const
    {
        return type;
    }

    const std::string &getName() const
    {
        return attributeName;
    }

private:
    int intValue;
    float floatValue;
    ATTRIBUTE_TYPE type;
    std::string attributeName;
};
}
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

#include "clnoise/basemodule.h"

namespace CLNoise
{

class Function : public BaseModule
{
public:
    Function(const std::string &mName, const char *kSource);
    ~Function();

    void setProto(const char *proto) { m_functionProto = proto;}
    const char* getProto() { return m_functionProto;}

private:
    const char *m_functionProto;
};

}
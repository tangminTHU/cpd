/******************************************************************************
* Coherent Point Drift
* Copyright (C) 2014 Pete Gadomski <pete.gadomski@gmail.com>
* 
* Derived from the Coherent Point Drift Matlab package
* Copyright (C) 2008-2009 Andriy Myronenko <myron@csee.ogi.edu>
* https://sites.google.com/site/myronenko/research/cpd
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
******************************************************************************/

#pragma once

#include <cpd/registration/base.hpp>


namespace cpd
{
namespace registration
{


class Rigid : public Base
{
public:

    explicit Rigid(
            float tol = 1e-5,
            int max_it = 150,
            float outliers = 0.1,
            bool use_fgt = false,
            bool strict_rot = true,
            bool use_scaling = true
            );
    
    inline bool strict_rot() const { return m_strict_rot; }
    inline bool use_scaling() const { return m_use_scaling; }

    inline void strict_rot(bool strict_rot) { m_strict_rot = strict_rot; }
    inline void use_scaling(bool use_scaling) { m_use_scaling = use_scaling; }

    virtual ~Rigid() {};

private:
    virtual SpResult execute(const arma::mat& X, const arma::mat& Y) const;

    bool m_strict_rot;
    bool m_use_scaling;

};


}
}

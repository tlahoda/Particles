/**
 * \file common.h, Contains common functions used in the particle system.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef PARTICLE_COMMON_H
#define PARTICLE_COMMON_H

#include <boost/numeric/ublas/vector.hpp>

namespace particle {
    /**
     * \typedef boost::numeric::ublas::vector<float> Vector,
     *          renamespacing of the ublas Vector class into the particles namespace.
     *          This is to help code clarity, particles::Vector as oppossed to 
     *          boost::numeric::ublas::vector<float>.
     */
    typedef boost::numeric::ublas::vector<float> Vector;

    /**
     * Creates a 3 element vector of floats from the inputs.
     *
     * \param x float, The x-coordinate.
     * \param y float, The y-coordinate.
     * \param z float, The z-coordinate.
     *
     * \return Vector, The Vector.
     */
    Vector make_Vector (float x, float y, float z) {
        Vector vec (3);
        vec[0] = x;
        vec[1] = y;
        vec[2] = z;
        return vec;
    }; //make_Vector

    /**
     * The gravitational acceleration vector.
     */
    static Vector GRAV_ACCEL = make_Vector (0.0f, -9.8f, 0.0f);

    /**
     * Delta T for the physics calculations. This will become a functor to get the inlining
     *
     * \return float, The current deltaT.
     */
    static float deltaT () {
        static const float dt = 0.033f;
        return dt;
    }; //deltaT
}; //particle

#endif //PARTICLE_COMMON_H


/**
 * \file Renderer.h, Contains the Renderer class.
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
#ifndef PARTICLE_RENDERER_H
#define PARTICLE_RENDERER_H

#include <algorithm>

#include "particles/common.h"

#include "gl/Primitive.h"
#include "gl/Matrix.h"

namespace particle {
    /**
     * \class Renderer, Renders particles using the given model.
     *
     * \param Model, The type of the model.
     */
    template<class Model>
    class Renderer {
        private:
            /**
             * \class Render, Renders a model for a particle.
             */
            class Render {
                public:
                    /**
                     * Renders a particle using the given model.
                     *
                     * \param model const Model&, The model to render for a particle.
                     */
                    explicit Render (const Model& model)
                      : model_ (model) {};

                    /**
                     * Render a model for a particle.
                     *
                     * \param Particle, The type of the particle.
                     *
                     * \param particle const Particle&, The particle to render.
                     *
                     * \return void.
                     */
                    template<class Particle>
                    void operator() (const Particle& particle) const { model_ (particle); };

                private:
                    /**
                     * The model to render for a particle.
                     */
                    Model model_;
            }; //Render

        public:
            /**
             * Constructs a Renderer for a model.
             *
             * \param model const Model&, The model to render.
             */
            explicit Renderer (const Model& model)
              : render_ (model) {};

            /**
             * Renders the sequence specified bt the iterators.
             *
             * \param Iterator, The type of the iterators.
             *
             * \param begin const Iterator& , The start of the sequence.
             * \param end const Iterator& , The end of the sequence.
             * \param origin const Vector&, The origin from which to render.
             *
             * \return void.
             */
            template<class Iterator>
            void operator() (const Iterator& begin, const Iterator& end, const Vector& origin) const {
                gl::Matrix matrix;
                //matrix.reset ();
                matrix.translate (origin);
 
                gl::Primitive<typename Model::glType> primitive;
                for (Iterator cur = begin; cur != end; ++cur) render_ (*cur);
            };

            /**
             * Renders a group.
             *
             * \param Group, The type of the group.
             *
             * \param particles const Group&, The group to render.
             *
             * \return void.
             */
            template<class Group>
            void operator() (const Group& particles) const {
                operator()<typename Group::iterator> (particles.begin (), particles.end (), particles.origin ());
            };

        private:
            /**
             * The Render to render a particle.
             */
            Render render_;
    }; //Renderer
}; //particle

#endif //PARTICLE_RENDERER_H


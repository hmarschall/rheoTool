/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    GMRES

SourceFiles
    GMRES.C

\*---------------------------------------------------------------------------*/

#ifndef GMRES_H
#define GMRES_H

#include "HypreIJSolver.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace HypreIJSolvers
{ 

/*---------------------------------------------------------------------------*\
                           Class GMRES Declaration
\*---------------------------------------------------------------------------*/

class GMRES
:
    public HypreIJSolver
{
    // Private data

      
 
    // Private Member Functions

        //- Disallow default bitwise copy construct
        GMRES(const GMRES&);

        //- Disallow default bitwise assignment
        void operator=(const GMRES&);
        
protected:

       
 
public:

    //- Runtime type information
    TypeName("GMRES");

    // Constructors

        //- Construct from components
        GMRES
        (
            const dictionary& dict
        );


    // Destructor

        virtual ~GMRES()
        {}


    // Member Functions
    
        //- Set user-defined options controlling the solver 
        virtual void initialize(HYPRE_Solver&) const;
                
        //- Setup and compute preconditioner if it applies        
        virtual void setup
        (
          HYPRE_Solver&, 
          HYPRE_Solver&,
          HYPRE_ParCSRMatrix&,
          HYPRE_ParVector&,
          HYPRE_ParVector&,
          HYPRE_PtrToSolverFcn,
          HYPRE_PtrToSolverFcn,
          bool
        ) const;
               
        //- Solve
        virtual void solve
        (
          HYPRE_Solver&, 
          HYPRE_ParCSRMatrix&,
          HYPRE_ParVector&,
          HYPRE_ParVector&
        );
        
        //- Destroy
        virtual void destroy(HYPRE_Solver&) const;
        
        //- Return the name of the solver
        virtual const word solverName() const
        {
          return "GMRES";
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace HypreIJSolvers 
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

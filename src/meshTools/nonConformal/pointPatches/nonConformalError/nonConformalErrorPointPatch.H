/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2021-2022 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::nonConformalErrorPointPatch

Description
    Constraint patch for errors associated with nonConformalCyclic couplings.

SourceFiles
    nonConformalErrorPointPatch.C

See also
    nonConformalErrorPlanePointPatch

\*---------------------------------------------------------------------------*/

#ifndef nonConformalErrorPointPatch_H
#define nonConformalErrorPointPatch_H

#include "facePointPatch.H"
#include "nonConformalErrorPolyPatch.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                     Class nonConformalErrorPointPatch Declaration
\*---------------------------------------------------------------------------*/

class nonConformalErrorPointPatch
:
    public facePointPatch
{

public:

    //- Runtime type information
    TypeName(nonConformalErrorPolyPatch::typeName_());


    // Constructors

        //- Construct from polyPatch
        nonConformalErrorPointPatch
        (
            const polyPatch& patch,
            const pointBoundaryMesh& bm
        )
        :
            facePointPatch(patch, bm)
        {}
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

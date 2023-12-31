/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2023 OpenFOAM Foundation
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
    Foam::constTransport

Description
    Transport package with constant properties

Usage
    \table
        Property     | Description
        mu           | Constant dynamic viscosity [Pa.s]
        Pr           | Constant Prandtl number []
    \endtable

    Example specification of constTransport for air:
    \verbatim
    transport
    {
        mu              1.82e-05;
        Pr              0.71;
    }
    \endverbatim

SourceFiles
    constTransportI.H
    constTransport.C

\*---------------------------------------------------------------------------*/

#ifndef constTransport_H
#define constTransport_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

template<class Thermo> class constTransport;

template<class Thermo>
inline constTransport<Thermo> operator+
(
    const constTransport<Thermo>&,
    const constTransport<Thermo>&
);

template<class Thermo>
inline constTransport<Thermo> operator*
(
    const scalar,
    const constTransport<Thermo>&
);

template<class Thermo>
Ostream& operator<<
(
    Ostream&,
    const constTransport<Thermo>&
);


/*---------------------------------------------------------------------------*\
                       Class constTransport Declaration
\*---------------------------------------------------------------------------*/

template<class Thermo>
class constTransport
:
    public Thermo
{
    // Private Data

        //- Constant dynamic viscosity [Pa.s]
        scalar mu_;

        //- Is the Prandtl Number constant?
        bool constPr_;

        //- Reciprocal constant Prandtl Number []
        scalar rPr_;

        //- Constant thermal conductivity [W/m/K]
        scalar kappa_;


public:

    // Constructors

        //- Construct from components
        inline constTransport
        (
            const Thermo& t,
            const scalar mu,
            const bool constPr,
            const scalar rPr,
            const scalar kappa
        );

        //- Construct as named copy
        inline constTransport(const word&, const constTransport&);

        //- Construct from name and dictionary
        constTransport(const word& name, const dictionary& dict);

        //- Construct and return a clone
        inline autoPtr<constTransport> clone() const;


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "const<" + Thermo::typeName() + '>';
        }

        //- Dynamic viscosity [kg/m/s]
        inline scalar mu(const scalar p, const scalar T) const;

        //- Thermal conductivity [W/m/K]
        inline scalar kappa(const scalar p, const scalar T) const;

        //- Write to Ostream
        void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const constTransport&);
        inline void operator*=(const scalar);


    // Friend operators

        friend constTransport operator+ <Thermo>
        (
            const constTransport&,
            const constTransport&
        );

        friend constTransport operator* <Thermo>
        (
            const scalar,
            const constTransport&
        );


    // Ostream Operator

        friend Ostream& operator<< <Thermo>
        (
            Ostream&,
            const constTransport&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "constTransportI.H"

#ifdef NoRepository
    #include "constTransport.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

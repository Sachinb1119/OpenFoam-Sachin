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

\*---------------------------------------------------------------------------*/

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Thermo>
inline Foam::constIsoSolidTransport<Thermo>::constIsoSolidTransport
(
    const Thermo& t,
    const scalar kappa
)
:
    Thermo(t),
    kappa_(kappa)
{}


template<class Thermo>
inline Foam::constIsoSolidTransport<Thermo>::constIsoSolidTransport
(
    const word& name,
    const constIsoSolidTransport& ct
)
:
    Thermo(name, ct),
    kappa_(ct.kappa_)
{}


template<class Thermo>
inline Foam::autoPtr<Foam::constIsoSolidTransport<Thermo>>
Foam::constIsoSolidTransport<Thermo>::clone() const
{
    return autoPtr<constIsoSolidTransport<Thermo>>
    (
        new constIsoSolidTransport<Thermo>(*this)
    );
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Thermo>
inline Foam::scalar Foam::constIsoSolidTransport<Thermo>::
kappa(const scalar p, const scalar T) const
{
    return kappa_;
}

template<class Thermo>
inline Foam::vector Foam::constIsoSolidTransport<Thermo>::
Kappa(const scalar p, const scalar T) const
{
    NotImplemented;
    return vector(kappa_, kappa_, kappa_);
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

template<class Thermo>
inline void Foam::constIsoSolidTransport<Thermo>::operator+=
(
    const constIsoSolidTransport<Thermo>& ct
)
{
    scalar Y1 = this->Y();
    Thermo::operator+=(ct);

    Y1 /= this->Y();
    scalar Y2 = ct.Y()/this->Y();

    kappa_ = Y1*kappa_ + Y2*ct.kappa_;
}


// * * * * * * * * * * * * * * * Friend Operators  * * * * * * * * * * * * * //


template<class Thermo>
inline Foam::constIsoSolidTransport<Thermo> Foam::operator*
(
    const scalar s,
    const constIsoSolidTransport<Thermo>& ct
)
{
    return constIsoSolidTransport<Thermo>
    (
        s*static_cast<const Thermo&>(ct),
        ct.kappa_
    );
}


// ************************************************************************* //

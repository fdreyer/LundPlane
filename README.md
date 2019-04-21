# LundPlane

Tools to construct the Lund plane of a jet.

## About

LundPlane is a fastjet plugin based on arXiv:1807.04758 by Frederic
Dreyer, Gavin Salam, and Gregory Soyez.

## Installation

To run the LundPlane code, you will need an installation of
[fastjet](http://fastjet.fr/), with fastjet-config in your path.

## Package

LundPlane provides the following C++ classes:

- LundDeclustering
  Contains the declustering variables associated with a node on
  the Lund plane.

- LundGenerator
  A tool to generate a vector of LundDeclustering for a given jet
  corresponding to its primary Lund plane.

- LundWithSecondary
  A tool to generate primary, and secondary, lund planes of a jet
  according to the definition given as input.

- SecondaryLund, SecondaryLund_{mMDT|dotmMDT|Mass}
  Provides a definition for the leading emission.

There is a C++ example

> make example
> ./example < data/single-event.dat

As well as producing output to screen, it generates a jets.json file,
which can be read by a python script:

> python3 ./example.py

Some python classes to assist with reading and processing the json file
are provided in the read_lund_json.py module.
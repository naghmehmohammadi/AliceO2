// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \author R+Preghenella - August 2017

#ifndef ALICEO2_EVENTGEN_GENERATORHEPMC_H_
#define ALICEO2_EVENTGEN_GENERATORHEPMC_H_

#include "Generators/Generator.h"
#include <fstream>

namespace HepMC
{
class Reader;
class GenEvent;
class FourVector;
} // namespace HepMC

namespace o2
{
namespace eventgen
{

/*****************************************************************/
/*****************************************************************/

class GeneratorHepMC : public Generator
{

 public:
  /** default constructor **/
  GeneratorHepMC();
  /** constructor **/
  GeneratorHepMC(const Char_t* name, const Char_t* title = "ALICEo2 HepMC Generator");
  /** destructor **/
  ~GeneratorHepMC() override;

  /** Initialize the generator if needed **/
  Bool_t Init() override;

  /** setters **/
  void setVersion(Int_t val) { mVersion = val; };
  void setFileName(std::string val) { mFileName = val; };

 protected:
  /** copy constructor **/
  GeneratorHepMC(const GeneratorHepMC&);
  /** operator= **/
  GeneratorHepMC& operator=(const GeneratorHepMC&);

  /** methods to override **/
  Bool_t generateEvent() override;
  Bool_t boostEvent(Double_t boost) override;
  Bool_t addTracks(FairPrimaryGenerator* primGen) const override;

  /** methods **/
  const HepMC::FourVector getBoostedVector(const HepMC::FourVector& vector, Double_t boost);

  /** HepMC interface **/
  std::ifstream mStream; //!
  std::string mFileName;
  Int_t mVersion;
  HepMC::Reader* mReader;  //!
  HepMC::GenEvent* mEvent; //!

  ClassDefOverride(GeneratorHepMC, 1);

}; /** class GeneratorHepMC **/

/*****************************************************************/
/*****************************************************************/

} // namespace eventgen
} // namespace o2

#endif /* ALICEO2_EVENTGEN_GENERATORHEPMC_H_ */


#ifndef __vtkMRMLLORLinearObjectNode_h
#define __vtkMRMLLORLinearObjectNode_h

// Standard includes
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

// VTK includes
#include "vtkSmartPointer.h"
#include "vtkObject.h"
#include "vtkObjectBase.h"
#include "vtkObjectFactory.h"
#include "vtkXMLDataElement.h"
#include "vtkPolyData.h"

// LinearObjectRegistration includes
#include "vtkMRMLLORVectorMath.h"

#include "vtkMRMLLORPositionBufferNode.h"
#include "vtkSlicerLinearObjectRegistrationModuleMRMLExport.h"

// This class stores a vector of values and a string label
class VTK_SLICER_LINEAROBJECTREGISTRATION_MODULE_MRML_EXPORT
vtkMRMLLORLinearObjectNode : public vtkObject
{
public:
  vtkTypeMacro( vtkMRMLLORLinearObjectNode, vtkObject );

  // No "New" function - this class will be abstract

protected:

  // Constructor/Destructor
  vtkMRMLLORLinearObjectNode();
  virtual ~vtkMRMLLORLinearObjectNode();

public:

  static const int DIMENSION = 3;
  static const int MODEL_SCALE = 100;

  double DistanceToVector( std::vector<double> vector );

  vtkMRMLLORPositionBufferNode* GetPositionBuffer();
  void SetPositionBuffer( vtkMRMLLORPositionBufferNode* newPositionBuffer );

  void Filter( int filterWidth );

  // Setters need to trigger modified events
  std::string GetName();
  void SetName( std::string newName );
  std::string GetType();
  void SetType( std::string newType );
  std::vector<double> GetSignature();
  void SetSignature( std::vector<double> newSignature );
  std::vector<double> GetBasePoint();
  void SetBasePoint( std::vector<double> newBasePoint );
  std::string GetModelID();
  void SetModelID( std::string newModelID );

  // Abstract functions that must be implemented in subclasses
  virtual vtkSmartPointer< vtkMRMLLORLinearObjectNode > DeepCopy() = 0;

  virtual vtkPolyData* CreateModelPolyData() = 0;

  virtual std::vector<double> ProjectVector( std::vector<double> vector ) = 0;
  virtual void Translate( std::vector<double> vector ) = 0;

  virtual std::string ToXMLString() = 0;
  virtual void FromXMLElement( vtkXMLDataElement* element ) = 0;

protected:

  std::string Name;
  std::string Type;
  std::string ModelID;
  std::vector<double> Signature;
  std::vector<double> BasePoint;

  vtkSmartPointer< vtkMRMLLORPositionBufferNode > PositionBuffer;

};


#endif
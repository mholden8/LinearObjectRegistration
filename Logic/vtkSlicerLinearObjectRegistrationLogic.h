
// .NAME vtkSlicerLinearObjectRegistrationLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerLinearObjectRegistrationLogic_h
#define __vtkSlicerLinearObjectRegistrationLogic_h

#include "LinearObject.h"
#include "LinearObjectBuffer.h"
#include "Point.h"
#include "Line.h"
#include "Plane.h"
#include "Reference.h"
#include "PointObservation.h"
#include "PointObservationBuffer.h"


// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes
#include "vtkMRML.h"
#include "vtkMRMLLinearTransformNode.h"
#include "vtkMRMLModelNode.h"

// STD includes
#include <cstdlib>

#include "vtkSmartPointer.h"
#include "vtkXMLDataParser.h"

#include "vtkSlicerLinearObjectRegistrationModuleLogicExport.h"

#include "vnl/vnl_matrix.h"



/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_LINEAROBJECTREGISTRATION_MODULE_LOGIC_EXPORT
vtkSlicerLinearObjectRegistrationLogic
 : public vtkSlicerModuleLogic
{

// This is general logic ----------------------------------------------------------------

public:

  static vtkSlicerLinearObjectRegistrationLogic *New();
  vtkTypeMacro(vtkSlicerLinearObjectRegistrationLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  virtual void OnMRMLSceneEndClose();
 
  
protected:
  
  vtkSlicerLinearObjectRegistrationLogic();
  virtual ~vtkSlicerLinearObjectRegistrationLogic();
  
  virtual void SetMRMLSceneInternal( vtkMRMLScene* newScene );
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded( vtkMRMLNode* node );
  virtual void OnMRMLSceneNodeRemoved( vtkMRMLNode* node );
  

private:

  vtkSlicerLinearObjectRegistrationLogic(const vtkSlicerLinearObjectRegistrationLogic&); // Not implemented
  void operator=(const vtkSlicerLinearObjectRegistrationLogic&);               // Not implemented


// Specific LinearObjectRegistration logic -----------------------------------------------

public:
  void ImportGeometry( std::string fileName );
  void ImportRecord( std::string fileName );
  void Register();
  void SetRegistrationTransformNode( vtkMRMLLinearTransformNode* newRegistrationTransformNode );



private:

  LinearObjectBuffer* GeometryBuffer;
  LinearObjectBuffer* GeometryPointBuffer;
  LinearObjectBuffer* GeometryLineBuffer;
  LinearObjectBuffer* GeometryPlaneBuffer;
  LinearObjectBuffer* GeometryReferenceBuffer;

  LinearObjectBuffer* RecordBuffer;
  LinearObjectBuffer* RecordPointBuffer;
  LinearObjectBuffer* RecordLineBuffer;
  LinearObjectBuffer* RecordPlaneBuffer;
  LinearObjectBuffer* RecordReferenceBuffer;

  std::vector<PointObservationBuffer*> ReferencePoints;
  std::vector<PointObservationBuffer*> LinearObjectPoints;

  vtkMRMLLinearTransformNode* RegistrationTransformNode;

};

#endif

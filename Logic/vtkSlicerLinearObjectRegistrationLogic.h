
// .NAME vtkSlicerLinearObjectRegistrationLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerLinearObjectRegistrationLogic_h
#define __vtkSlicerLinearObjectRegistrationLogic_h


// Standard includes
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <limits>

// VTK includes
#include "vtkObject.h"
#include "vtkObjectBase.h"
#include "vtkObjectFactory.h"
#include "vtkXMLDataElement.h"
#include "vtkSmartPointer.h"
#include "vtkXMLDataParser.h"
#include "vtkNew.h"
#include "vtkIntArray.h"
#include "vtkMatrix4x4.h"

// VNL includes
#include "vnl/vnl_matrix.h"

// Slicer includes
#include "vtkSlicerModuleLogic.h"
#include "vtkMRMLLinearTransformNode.h"
#include "vtkMRMLModelNode.h"
#include "vtkMRMLScene.h"
#include "vtkMRMLSelectionNode.h"
#include "vtkMRMLDisplayNode.h"
#include "vtkMRMLModelDisplayNode.h"

// LinearObjectRegistration includes
#include "vtkMRMLLinearObjectRegistrationNode.h"
#include "vtkMRMLLORLinearObjectCollectionNode.h"
#include "vtkMRMLLORPointNode.h"
#include "vtkMRMLLORLineNode.h"
#include "vtkMRMLLORPlaneNode.h"
#include "vtkMRMLLORReferenceNode.h"
#include "vtkMRMLLORPositionBufferNode.h"
#include "vtkSlicerLinearObjectRegistrationModuleLogicExport.h"




/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_LINEAROBJECTREGISTRATION_MODULE_LOGIC_EXPORT
vtkSlicerLinearObjectRegistrationLogic : public vtkSlicerModuleLogic
{

// This is general logic ----------------------------------------------------------------

public:

  static vtkSlicerLinearObjectRegistrationLogic *New();
  vtkTypeMacro(vtkSlicerLinearObjectRegistrationLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  virtual void OnMRMLSceneEndClose();
 
  void ProcessMRMLNodesEvents( vtkObject* caller, unsigned long event, void* callData );
  void ProcessMRMLSceneEvents( vtkObject* caller, unsigned long event, void* callData );
  
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

  void CalculateTransform( vtkMRMLNode* node );
  void UpdateOutputTransform( vtkMRMLLinearTransformNode* outputTransform, vnl_matrix<double>* newTransformMatrix );
  void UpdateOutputTransform( vtkMRMLLinearTransformNode* outputTransform, vnl_matrix<double>* newRotationMatrix, vnl_matrix<double>* newRotationVector );

  vnl_matrix<double>* SphericalRegistration( vtkMRMLLORPositionBufferNode* fromPoints, vtkMRMLLORPositionBufferNode* toPoints );
  vnl_matrix<double>* TranslationalRegistration( std::vector<double> toCentroid, std::vector<double> fromCentroid, vnl_matrix<double>* rotation );

  vnl_matrix<double>* LinearObjectICP( vnl_matrix<double>* initialRotation );

  std::string GetOutputMessage();
  void SetOutputMessage( std::string newOutputMessage );

  vtkSmartPointer< vtkMRMLLORLinearObjectNode > PositionBufferToLinearObject( vtkMRMLLORPositionBufferNode* positionBuffer, int dof = -1 );

  void ObserveTransformNode( vtkMRMLNode* node );

  vtkMRMLLORLinearObjectCollectionNode* GetActiveCollectionNode();
  void SetActiveCollectionNode( vtkMRMLLORLinearObjectCollectionNode* newActiveCollectionNode );

  void FinalizeActivePositionBuffer();
  void InitializeActivePositionBuffer( std::string collectType );

  void InsertNewLinearObject( vtkMRMLLORLinearObjectNode* linearObject );

  void MatchCollections( vtkMRMLLORLinearObjectCollectionNode* collection0, vtkMRMLLORLinearObjectCollectionNode* collection1, bool removeUnmatched = false );
  vtkSmartPointer< vtkMRMLLORLinearObjectCollectionNode > GetReferences( vtkMRMLLORLinearObjectCollectionNode* collection );
  vtkSmartPointer< vtkMRMLLORLinearObjectCollectionNode > GetNonReferences( vtkMRMLLORLinearObjectCollectionNode* collection );

  void ToggleLinearObjectModelVisibility( vtkMRMLLORLinearObjectNode* linearObject );

  // Only to be called from the register method
  void GetFromAndToCollections( vtkMRMLLORLinearObjectCollectionNode* fromCollection, vtkMRMLLORLinearObjectCollectionNode* fromReferenceCollection, vtkMRMLLORLinearObjectCollectionNode* fromPointCollection, vtkMRMLLORLinearObjectCollectionNode* fromLineCollection, vtkMRMLLORLinearObjectCollectionNode* fromPlaneCollection,
                          vtkMRMLLORLinearObjectCollectionNode* toCollection, vtkMRMLLORLinearObjectCollectionNode* toReferenceCollection, vtkMRMLLORLinearObjectCollectionNode* toPointCollection, vtkMRMLLORLinearObjectCollectionNode* toLineCollection, vtkMRMLLORLinearObjectCollectionNode* toPlaneCollection );

private:

  vtkMRMLLinearTransformNode* ObservedTransformNode;
  vtkSmartPointer< vtkMRMLLORPositionBufferNode > ActivePositionBuffer;
  std::string CollectType;

  std::string OutputMessage;

};

#endif

/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLLinearObjectRegistrationNode.h,v $
  Date:      $Date: 2006/03/19 17:12:28 $
  Version:   $Revision: 1.6 $

=========================================================================auto=*/

#ifndef __vtkMRMLLinearObjectRegistrationNode_h
#define __vtkMRMLLinearObjectRegistrationNode_h

#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

#include "vtkMRMLNode.h"
#include "vtkMRMLScene.h"
#include "vtkMRMLLinearTransformNode.h"
#include "vtkCommand.h"
#include "vtkNew.h"
#include "vtkIntArray.h"
#include "vtkObject.h"
#include "vtkObjectBase.h"
#include "vtkObjectFactory.h"

#include "vtkLORRealTimePositionBuffer.h"

// LinearObjectRegistration includes
#include "vtkSlicerLinearObjectRegistrationModuleMRMLExport.h"


class
VTK_SLICER_LINEAROBJECTREGISTRATION_MODULE_MRML_EXPORT
vtkMRMLLinearObjectRegistrationNode
: public vtkMRMLNode
{
public:
  vtkTypeMacro( vtkMRMLLinearObjectRegistrationNode, vtkMRMLNode );
  
  // Standard MRML node methods  
  static vtkMRMLLinearObjectRegistrationNode *New();  

  virtual vtkMRMLNode* CreateNodeInstance();
  virtual const char* GetNodeTagName() { return "LinearObjectRegistration"; };
  void PrintSelf( ostream& os, vtkIndent indent );
  virtual void ReadXMLAttributes( const char** atts );
  virtual void WriteXML( ostream& of, int indent );
  virtual void Copy( vtkMRMLNode *node );
  
protected:

  // Constructor/desctructor methods
  vtkMRMLLinearObjectRegistrationNode();
  virtual ~vtkMRMLLinearObjectRegistrationNode();
  vtkMRMLLinearObjectRegistrationNode ( const vtkMRMLLinearObjectRegistrationNode& );
  void operator=( const vtkMRMLLinearObjectRegistrationNode& );
 
  
public:
  // Enumerate all the possible modified states
  enum ModifyType
  {
    NeverModify,
    DefaultModify,
    AlwaysModify
  };

  enum PositionBufferEvent
  {
    PositionBufferReady = vtkCommand::UserEvent + 1
  };

  // Use default setters and getters - vtk set macro will cause modified event
  //void SetCollectTransformID( std::string newCollectTransformID, int modifyType = DefaultModify );
  void SetFromCollectionID( std::string newFromCollectionID, int modifyType = DefaultModify );
  void SetToCollectionID( std::string newToCollectionID, int modifyType = DefaultModify );
  void SetOutputTransformID( std::string newOutputTransformID, int modifyType = DefaultModify );

  void SetCollectMode( std::string newCollectMode, int modifyType = DefaultModify );

  void SetAutomaticMatch( bool newAutomaticMatch, int modifyType = DefaultModify );
  void SetAutomaticMerge( bool newAutomaticMerge, int modifyType = DefaultModify );
  void SetMergeThreshold( double newMergeThreshold, int modifyType = DefaultModify );
  void SetNoiseThreshold( double newNoiseThreshold, int modifyType = DefaultModify );
  void SetMatchingThreshold( double newMatchingThreshold, int modifyType = DefaultModify );
  void SetMinimumCollectionPositions( int newMinimumCollectionPositions, int modifyType = DefaultModify );
  void SetTrimPositions( int newTrimPositions, int modifyType = DefaultModify );

  //std::string GetCollectTransformID();
  std::string GetFromCollectionID();
  std::string GetToCollectionID();
  std::string GetOutputTransformID();

  std::string GetCollectMode();

  bool GetAutomaticMatch();
  bool GetAutomaticMerge();
  double GetMergeThreshold();
  double GetNoiseThreshold();
  double GetMatchingThreshold();
  int GetMinimumCollectionPositions();
  int GetTrimPositions();

  std::string GetNodeReferenceIDString( std::string referenceRole );

  void ObserveAllReferenceNodes();

  std::string GetCollectState();
  vtkLORPositionBuffer* GetActivePositionBuffer();

  bool DifferentFromPrevious( vtkMatrix4x4* newMatrix );

  void SetCollectTypeNode( vtkMRMLNode* newCollectNode );
  void StartCollecting( vtkMRMLNode* newCollectNode, std::string newCollectState );
  void StopCollecting();

  void ProcessMRMLEvents( vtkObject *caller, unsigned long event, void *callData );

private:

  vtkNew< vtkIntArray > ObserveEvents;

  void ProcessTransformCollectNodeUpdate( vtkMRMLLinearTransformNode* transformNode );

  std::string CollectMode;
  bool AutomaticMatch;
  bool AutomaticMerge;

  std::string CollectState;
  vtkSmartPointer< vtkLORRealTimePositionBuffer > ActivePositionBuffer;
  vtkSmartPointer< vtkMatrix4x4 > PreviousMatrix;

  double NoiseThreshold;
  double MatchingThreshold;
  double MergeThreshold;
  int MinimumCollectionPositions;
  int TrimPositions;

};  

#endif

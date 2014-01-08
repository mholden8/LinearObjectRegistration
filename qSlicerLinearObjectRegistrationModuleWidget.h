
#ifndef __qSlicerLinearObjectRegistrationModuleWidget_h
#define __qSlicerLinearObjectRegistrationModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerLinearObjectRegistrationModuleExport.h"

class qSlicerLinearObjectRegistrationModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_LINEAROBJECTREGISTRATION_EXPORT qSlicerLinearObjectRegistrationModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerLinearObjectRegistrationModuleWidget(QWidget *parent=0);
  virtual ~qSlicerLinearObjectRegistrationModuleWidget();

public slots:

  void OnTransformNodeSelected( vtkMRMLNode* );
  void OnRegisterButtonClicked();
  void OnMatchButtonClicked();

  void OnFromMatchRequested( int matchIndex );
  void OnToMatchRequested( int matchIndex );

protected:
  QScopedPointer<qSlicerLinearObjectRegistrationModuleWidgetPrivate> d_ptr;
  
  virtual void setup();

private:
  Q_DECLARE_PRIVATE(qSlicerLinearObjectRegistrationModuleWidget);
  Q_DISABLE_COPY(qSlicerLinearObjectRegistrationModuleWidget);
  
  void UpdateGUI();

  int FromMatchState;
  int ToMatchState;
  
  double TimerIntervalSec;
  QTimer* Timer;
  
};

#endif

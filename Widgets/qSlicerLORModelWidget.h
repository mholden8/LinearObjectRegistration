/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerLORModelWidget_h
#define __qSlicerLORModelWidget_h

// Qt includes
#include "qSlicerWidget.h"
#include "qSlicerLORCollectControlsWidget.h"

#include "qSlicerApplication.h"

// FooBar Widgets includes
#include "qSlicerLinearObjectRegistrationModuleWidgetsExport.h"
#include "ui_qSlicerLORModelWidget.h"

#include "vtkSlicerLinearObjectRegistrationLogic.h"

#include "vtkMRMLInteractionNode.h"



class qSlicerLORModelWidgetPrivate;

/// \ingroup Slicer_QtModules_CreateModels
class Q_SLICER_MODULE_LINEAROBJECTREGISTRATION_WIDGETS_EXPORT 
qSlicerLORModelWidget : public qSlicerLORCollectControlsWidget
{
  Q_OBJECT
public:
  typedef qSlicerLORCollectControlsWidget Superclass;
  qSlicerLORModelWidget( QWidget *parent = 0 );
  qSlicerLORModelWidget( vtkSlicerLinearObjectRegistrationLogic* LORLogic, QWidget *parent = 0 );
  virtual ~qSlicerLORModelWidget();

  static qSlicerLORModelWidget* New( vtkSlicerLinearObjectRegistrationLogic* newLORLogic );

  virtual std::string GetCollectNodeType();
  virtual std::string GetCollectModeName();

public slots:

  virtual void widgetActivated();
  virtual void widgetDeactivated();

protected slots:

  void onReferenceShortcutRActivated();
  void onReferenceButtonToggled();
  void onReferenceFiducialDropped();

  void onPointShortcutPActivated();
  void onPointButtonToggled();
  void onPointFiducialDropped();

  void onLineShortcutLActivated();
  void onLineButtonToggled();
  void onLineFiducialDropped();

  void onPlaneShortcutAActivated();
  void onPlaneButtonToggled();
  void onPlaneFiducialDropped();

  void onClickRequested();

  void disconnectMarkupsObservers( std::string checkString = "" );

  void updateWidget();

protected:
  QScopedPointer<qSlicerLORModelWidgetPrivate> d_ptr;

  virtual void setup();
  virtual void enter();

  virtual void installShortcuts();
  virtual void uninstallShortcuts();

  QShortcut* ReferenceShortcutR;
  QShortcut* PointShortcutP;
  QShortcut* LineShortcutL;
  QShortcut* PlaneShortcutA;

private:
  Q_DECLARE_PRIVATE(qSlicerLORModelWidget);
  Q_DISABLE_COPY(qSlicerLORModelWidget);

  void ConnectAllButtons();
  void DisconnectAllButtons();
};

#endif

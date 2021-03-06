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

#ifndef __qSlicerLORAutomaticWidget_h
#define __qSlicerLORAutomaticWidget_h

// Qt includes
#include "qSlicerWidget.h"
#include "qSlicerLORCollectControlsWidget.h"

// FooBar Widgets includes
#include "qSlicerLinearObjectRegistrationModuleWidgetsExport.h"
#include "ui_qSlicerLORAutomaticWidget.h"

#include "vtkSlicerLinearObjectRegistrationLogic.h"


class qSlicerLORAutomaticWidgetPrivate;

/// \ingroup Slicer_QtModules_CreateModels
class Q_SLICER_MODULE_LINEAROBJECTREGISTRATION_WIDGETS_EXPORT 
qSlicerLORAutomaticWidget : public qSlicerLORCollectControlsWidget
{
  Q_OBJECT
public:
  typedef qSlicerLORCollectControlsWidget Superclass;
  qSlicerLORAutomaticWidget( QWidget *parent = 0 );
  qSlicerLORAutomaticWidget( vtkSlicerLinearObjectRegistrationLogic* newLORLogic, QWidget *parent = 0 );
  virtual ~qSlicerLORAutomaticWidget();

  static qSlicerLORAutomaticWidget* New( vtkSlicerLinearObjectRegistrationLogic* newLORLogic );

  virtual std::string GetCollectNodeType();
  virtual std::string GetCollectModeName();

  virtual void SetAndObserveCollectNode( vtkMRMLNode* newCollectNode );

public slots:

  virtual void widgetActivated();
  virtual void widgetDeactivated();

protected slots:

  void updateWidget();

protected:
  QScopedPointer<qSlicerLORAutomaticWidgetPrivate> d_ptr;

  virtual void setup();
  virtual void enter();

private:
  Q_DECLARE_PRIVATE(qSlicerLORAutomaticWidget);
  Q_DISABLE_COPY(qSlicerLORAutomaticWidget);
};

#endif

project(qSlicer${MODULE_NAME}ModuleWidgets)

set(KIT ${PROJECT_NAME})

set(${KIT}_EXPORT_DIRECTIVE "Q_SLICER_MODULE_${MODULE_NAME_UPPER}_WIDGETS_EXPORT")

set(${KIT}_INCLUDE_DIRECTORIES
  ${vtkSlicer${MODULE_NAME}ModuleUtilities_SOURCE_DIR}
  ${vtkSlicer${MODULE_NAME}ModuleUtilities_BINARY_DIR}
  )

set(${KIT}_SRCS
  qSlicerLinearObjectCollectionWidget.cxx
  qSlicerLinearObjectCollectionWidget.h
  qSlicerLORCollectWidget.cxx
  qSlicerLORCollectWidget.h
  qSlicerLORCollectControlsWidget.cxx
  qSlicerLORCollectControlsWidget.h
  qSlicerLORManualDOFWidget.cxx
  qSlicerLORManualDOFWidget.h
  qSlicerLORManualSegmentationWidget.cxx
  qSlicerLORManualSegmentationWidget.h
  qSlicerLORAutomaticWidget.cxx
  qSlicerLORAutomaticWidget.h
  qSlicerLORModelWidget.cxx
  qSlicerLORModelWidget.h
  qSlicerLORFiducialWidget.cxx
  qSlicerLORFiducialWidget.h
  qSlicerTransformPreviewWidget.cxx
  qSlicerTransformPreviewWidget.h
  )

set(${KIT}_MOC_SRCS
  qSlicerLinearObjectCollectionWidget.h
  qSlicerLORCollectWidget.h
  qSlicerLORCollectControlsWidget.h  
  qSlicerLORManualDOFWidget.h
  qSlicerLORManualSegmentationWidget.h
  qSlicerLORAutomaticWidget.h
  qSlicerLORModelWidget.h
  qSlicerLORFiducialWidget.h
  qSlicerTransformPreviewWidget.h
  )

set(${KIT}_UI_SRCS
  ./Resources/UI/qSlicerLinearObjectCollectionWidget.ui
  ./Resources/UI/qSlicerLORCollectControlsWidget.ui
  ./Resources/UI/qSlicerLORCollectWidget.ui
  ./Resources/UI/qSlicerLORManualDOFWidget.ui
  ./Resources/UI/qSlicerLORManualSegmentationWidget.ui
  ./Resources/UI/qSlicerLORAutomaticWidget.ui
  ./Resources/UI/qSlicerLORModelWidget.ui
  ./Resources/UI/qSlicerLORFiducialWidget.ui
  ./Resources/UI/qSlicerTransformPreviewWidget.ui
  )

set(${KIT}_RESOURCES
  ./Resources/UI/qSlicerLinearObjectCollectionWidget.ui
  ./Resources/UI/qSlicerLORCollectControlsWidget.ui
  ./Resources/UI/qSlicerLORCollectWidget.ui
  ./Resources/UI/qSlicerLORManualDOFWidget.ui
  ./Resources/UI/qSlicerLORManualSegmentationWidget.ui
  ./Resources/UI/qSlicerLORAutomaticWidget.ui
  ./Resources/UI/qSlicerLORModelWidget.ui
  ./Resources/UI/qSlicerLORFiducialWidget.ui
  ./Resources/UI/qSlicerTransformPreviewWidget.ui
  )

set(${KIT}_TARGET_LIBRARIES
  vtkSlicer${MODULE_NAME}ModuleLogic
  )

#-----------------------------------------------------------------------------
SlicerMacroBuildModuleWidgets(
  NAME ${KIT}
  EXPORT_DIRECTIVE ${${KIT}_EXPORT_DIRECTIVE}
  INCLUDE_DIRECTORIES ${${KIT}_INCLUDE_DIRECTORIES}
  SRCS ${${KIT}_SRCS}
  MOC_SRCS ${${KIT}_MOC_SRCS}
  UI_SRCS ${${KIT}_UI_SRCS}
  TARGET_LIBRARIES ${${KIT}_TARGET_LIBRARIES}
  RESOURCES ${${KIT}_RESOURCES}
  WRAP_PYTHONQT
  )


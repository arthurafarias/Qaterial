/**
 * Copyright (C) Olivier Le Doeuff 2019
 * Contact: olivier.ldff@gmail.com
 */

// Qt
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Templates 2.12 as T

// Qaterial
import Qaterial 1.0 as Qaterial

T.Popup
{
  id: control

  implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                          contentWidth + leftPadding + rightPadding)
  implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                           contentHeight + topPadding + bottomPadding)

  padding: 12

  property color backgroundColor: Qaterial.Style.dialogColor

  background: Rectangle
  {
    implicitWidth: Qaterial.Style.menu.implicitWidth
    implicitHeight: Qaterial.Style.menu.implicitHeight

    radius: Qaterial.Style.menu.radius
    color: control.backgroundColor

    layer.enabled: control.elevation > 0
    layer.effect: Qaterial.ElevationEffect
    {
      elevation: control.elevation
    } // ElevationEffect
  } // Rectangle

  T.Overlay.modal: Rectangle
  {
    color: Qaterial.Style.overlayColor
    Behavior on opacity
    {
      NumberAnimation { duration: 150 } // NumberAnimation
    } // Behavior
  } // Rectangle

  T.Overlay.modeless: Rectangle
  {
    color: Qaterial.Style.overlayColor
    Behavior on opacity
    {
      NumberAnimation { duration: 150 } // NumberAnimation
    } // Behavior
  } // Rectangle
}

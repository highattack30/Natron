.. _net.sf.openfx.MultiplyPlugin:

MultiplyOFX
===========

.. figure:: net.sf.openfx.MultiplyPlugin.png
   :alt: 

*This documentation is for version 2.0 of MultiplyOFX.*

Multiply the selected channels by a constant.

See also: http://opticalenquiry.com/nuke/index.php?title=Multiply

Inputs
------

+----------+---------------+------------+
| Input    | Description   | Optional   |
+==========+===============+============+
| Source   |               | No         |
+----------+---------------+------------+
| Mask     |               | Yes        |
+----------+---------------+------------+

Controls
--------

+-------------------+---------------+-----------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
| Label (UI Name)   | Script-Name   | Type      | Default-Value         | Function                                                                                                                             |
+===================+===============+===========+=======================+======================================================================================================================================+
| Value             | value         | Color     | r: 1 g: 1 b: 1 a: 1   | Constant to multiply with the selected channels.                                                                                     |
+-------------------+---------------+-----------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
| (Un)premult       | premult       | Boolean   | Off                   | Divide the image by the alpha channel before processing, and re-multiply it afterwards. Use if the input images are premultiplied.   |
+-------------------+---------------+-----------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
| Invert Mask       | maskInvert    | Boolean   | Off                   | When checked, the effect is fully applied where the mask is 0.                                                                       |
+-------------------+---------------+-----------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+
| Mix               | mix           | Double    | 1                     | Mix factor between the original and the transformed image.                                                                           |
+-------------------+---------------+-----------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------+

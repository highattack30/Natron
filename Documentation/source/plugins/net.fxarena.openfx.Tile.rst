.. _net.fxarena.openfx.Tile:

TileOFX
=======

.. figure:: net.fxarena.openfx.Tile.png
   :alt: 

*This documentation is for version 3.2 of TileOFX.*

Tile transform node.

Powered by ImageMagick 7.0.3-4 Q32 x86\_64 2016-10-23 http://www.imagemagick.org

ImageMagick (R) is Copyright 1999-2015 ImageMagick Studio LLC, a non-profit organization dedicated to making software imaging solutions freely available.

ImageMagick is distributed under the Apache 2.0 license.

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

+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| Label (UI Name)    | Script-Name   | Type      | Default-Value   | Function                                                                                                |
+====================+===============+===========+=================+=========================================================================================================+
| Rows               | rows          | Integer   | 2               | Rows in grid                                                                                            |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| Colums             | cols          | Integer   | 2               | Columns in grid                                                                                         |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| Time Offset        | offset        | Integer   | 0               | Set a time offset                                                                                       |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| Keep first frame   | keepFirst     | Boolean   | On              | Stay on first frame if offset                                                                           |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| Matte              | matte         | Boolean   | Off             | Merge Alpha before applying effect                                                                      |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+
| OpenMP             | openmp        | Boolean   | Off             | Enable/Disable OpenMP support. This will enable the plugin to use as many threads as allowed by host.   |
+--------------------+---------------+-----------+-----------------+---------------------------------------------------------------------------------------------------------+

Cropper
=======

Crop and resize images

Description
-----------

Small Qt application to crop and resize images. For now command-line interface only.

TODO
----

* Commands should be command-line interface exclusive

    So we could create action components that are reusable, i.e. _Crop_ would extend a _ImageAction_ SuperClass instead of _Command_.
    That way, Commands would be cli exclusive, enabling reuse of ImageAction classes in the gui.

* Better cli output

    Cli outputs are done by _qDebug().operator<<__. It should be done by _QTextStream_ instead.


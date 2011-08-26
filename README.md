Cropper
=======

Crop and resize images

Description
-----------

Small Qt application to crop and resize images. For now command-line interface only.

TODO
----

* Commands should be command-line interface exclusive

    So we could create action components that are reusable, i.e. Crop would extend a ImageAction SuperClass instead of Command.
	That way, Commands would be cli exclusive, enabling reuse of ImageAction classes in the gui.

* Better cli output

    Cli outputs are done by qDebug().operator<<. It should be done by QTextStream instead.


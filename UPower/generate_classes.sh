QDBUS_UPOWER='qdbus --system org.freedesktop.UPower'
INTROSPECT='org.freedesktop.DBus.Introspectable.Introspect'
FILE_UPOWER=upower.xml

XML_OUT=$($QDBUS_UPOWER  /org/freedesktop/UPower/devices/DisplayDevice $INTROSPECT)
#handle error  Got unknown type `a{sv}'
HANDLED=$XML_OUT
#HANDLED=${HANDLED//\{/}
#HANDLED=${HANDLED//\}/}
#HANDLED=${HANDLED//\(/}
#HANDLED=${HANDLED//\)/}
echo $HANDLED > $FILE_UPOWER
#qdbusxml2cpp $FILE_UPOWER -p IPowerDisplayDeviceInterface --no-namespaces


#!/bin/sh

/home/player/challenge "$1"
code=$?

echo "[process exited with code $code]"
exit "$code"

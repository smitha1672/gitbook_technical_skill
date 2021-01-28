# Python Installation

[ref.1](https://www.itread01.com/content/1541040331.html)

# Trouble Shoot
## TS.1 No module named numpy

```text
ImportError: No module named numpy
```

## TS.2 pip install numpy

```text
Traceback (most recent call last):
    File "/home/smith/.local/bin/pip", line 7, in <module>
from pip._internal.cli.main import main
    File "/home/smith/.local/lib/python3.5/site-packages/pip/_internal/cli/main.py", line 60
sys.stderr.write(f"ERROR: {exc}")
                               ^
SyntaxError: invalid syntax
```

[fix](https://stackoverflow.com/questions/65869296/installing-pip-is-not-working-in-bitbucket-ci/65871131#65871131)

```text
- curl -O https://bootstrap.pypa.io/2.7/get-pip.py
- python get-pip.py
- python -m pip install --upgrade "pip < 21.0"
```

## TS.2 Cannot python

```text
$ whereis python
$ rm /usr/bin/python
$ ln -s /usr/bin/python3.4 /usr/local/bin/python
$ ln -s /usr/bin/python3.4 /usr/bin/python
```




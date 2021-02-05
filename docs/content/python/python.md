# Python

# Resource

[Tutorial.1](https://docs.python.org/3/tutorial/appetite.html) <br/>
[Data Structure](https://www.tutorialspoint.com/python_data_structure/index.htm) <br/>

# Installation

[ref.1](https://www.itread01.com/content/1541040331.html) <br/>
[ref.2](https://nbanzyme.medium.com/how-to-install-python3-in-ubuntu-16-04-19656ce4d326)<br/>
[ref.3](https://www.digitalocean.com/community/tutorials/how-to-install-python-3-and-set-up-a-local-programming-environment-on-ubuntu-16-04)

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




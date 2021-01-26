# uninstall python 2.7 in ubuntu

```text
apt list --installed | grep -E "python|pip"
```

<br/>
[uninstall python 2.7 in ubuntu](https://www.codegrepper.com/code-examples/delphi/uninstall+python+2.7+in+ubuntu)

<br/>
[How to remove libpython2.7-minimal from Ubuntu 14.04](https://howtoinstall.co/en/ubuntu/trusty/libpython2.7-minimal?action=remove)

<br/>
ubuntu remove python 2.7

```text
# Remove python2
sudo apt purge -y python2.7-minimal

# You already have Python3 but
# don't care about the version
sudo ln -s /usr/bin/python3 /usr/bin/python

# Same for pip
sudo apt install -y python3-pip
sudo ln -s /usr/bin/pip3 /usr/bin/pip

# Confirm the new version of Python: 3
python --version
```
<br/>
how to uninstall python2.7 from ubuntu 18.04

```text
sudo apt autoremove python
```

<br/>
how to uninstall python2.7 from ubuntu 18.04

```text
whereis python
which python
```

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


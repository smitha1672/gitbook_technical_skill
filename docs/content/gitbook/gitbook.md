## Gitbook
You have to install **Node.js**, **npm**, **tbook servegitbook**
[GitBool Toolchain Documentation; ](https://toolchain.gitbook.com/examples.html)
[how to install node.js on ubuntu 16.04:Native](https://www.digitalocean.com/community/tutorials/how-to-install-node-js-on-ubuntu-16-04)

+ book.json

```text
{
  "gitbook": "3.2.3",
  "root":"./docs",
  "plugins": ["fontsettings", "mermaid-gb3"], // add '-' meaning remove plugin
  "pluginsConfig": {
    "fontsettings": {
      "theme": "white",
      "family": "sans",
      "size": 2
    }
}
```

+ Put a illustrated figure with markdown

```text
<img src="acti-sensorhub-figure-1.png"
width="80%"
height="80%"
alt="acti-sensorhub-figure-1"
align=center />

<img src="https://bayanbox.ir/view/581244719208138556/virtual-memory.jpg"
width="100%"
height="100%"
alt="virtual memory"
align=center />
```

### ubuntu
Node.js, npm Installation

```bash
sudo apt-get update
sudo apt-get install nodejs
sudo apt-get install npm
sudo npm install gitbook-cli -g
```
<br> Preview with Firefox

```bash
gitbook init ./directory
cd ./directory
gitbook build
gitbook serve
```
<br> There are available message

```text
Live reload server started on port: 35729
Press CTRL+C to quit ...

info: 7 plugins are installed
info: loading plugin "livereload"... OK
info: loading plugin "highlight"... OK
info: loading plugin "search"... OK
info: loading plugin "lunr"... OK
info: loading plugin "sharing"... OK
info: loading plugin "fontsettings"... OK
info: loading plugin "theme-default"... OK
info: found 7 pages
info: found 2 asset files
info: >> generation finished with success in 1.9s !

Starting server ...
Serving book on http://localhost:4000
```
<br> Trouble Shooting
<br> Executing `gitbook init`, I got error message as

```text
/usr/bin/env: ‘node’: No such file or directory
[fix] ln -s /usr/bin/nodejs /usr/bin/node
```

### windows

[download and installation with node.js](https://nodejs.org/en/download/)
<br> checking `node -v` with windows `cmd`

```text
W:\github\gitbook_technical_skill>node -v
v8.11.3
```
<br> Install gitbook-cli with `npm install gitbook-cli -g` and windows `cmd`
<br> checking gitbook `gitbook` in windows `cmd`

```text
W:\github\gitbook_technical_skill>gitbook

Usage: gitbook [options] [command]


Options:

-v, --gitbook [version]  specify GitBook version to use
-d, --debug              enable verbose error
-V, --version            Display running versions of gitbook and gitbook-cli
-h, --help               output usage information


Commands:

ls                        List versions installed locally
current                   Display currently activated version
ls-remote                 List remote versions available for install
fetch [version]           Download and install a <version>
alias [folder] [version]  Set an alias named <version> pointing to <folder>
uninstall [version]       Uninstall a version
update [tag]              Update to the latest version of GitBook
help                      List commands for GitBook
*                         run a command with a specific gitbook version
```
<br> `gitbook build` and then `gitbook serve`

```text
Live reload server started on port: 35729
Press CTRL+C to quit ...

info: 7 plugins are installed
info: loading plugin "livereload"... OK
info: loading plugin "highlight"... OK
info: loading plugin "search"... OK
info: loading plugin "lunr"... OK
info: loading plugin "sharing"... OK
info: loading plugin "fontsettings"... OK
info: loading plugin "theme-default"... OK
info: found 7 pages
info: found 2 asset files
info: >> generation finished with success in 1.9s !

Starting server ...
Serving book on http://localhost:4000
```

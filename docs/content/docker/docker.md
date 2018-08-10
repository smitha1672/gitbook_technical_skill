## Docker
Refer as:
<br>[Ubuntu Docker Install](https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/)
<br>[Learn Docker](https://blog.gtwang.org/virtualization/ubuntu-linux-install-docker-tutorial/)
<br>[Docker Command Line](https://docs.docker.com/engine/reference/commandline/docker/)
<br>[Building a docker image](https://skychang.github.io/2015/07/30/%E5%BB%BA%E7%AB%8B%E8%87%AA%E5%B7%B1%E7%9A%84-Docker-image/)
<br>[Share docker image](https://larrylu.blog/share-image-on-dockerhub-ccb7d9b26fa8)
<br>[Entry docker](http://m.openfoundry.org/?action=news&page=/tw/tech-column/9319-docker-101)
<br>[other.1](https://philipzheng.gitbooks.io/docker_practice/content/install/ubuntu.html)
### Installation
Install
```bash
sudo apt-get install docker.io
```
Serve Checking
```bash
service docker status
```
Add my account to docker group
```bash
sudo usermod -aG docker smith
```
Checking Verion
```bash
docker version
```

### Pull ubuntu 16.04 or latest
```bash
docker pull ubuntu:16.04 #or ubuntu:latest
```

List images
```bash
docker images
```
```text
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
ubuntu              16.04               e13f3d529b1a        4 days ago          115 MB
```

### Export/Import a container
List contains
```text
$ sudo docker ps -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                    PORTS               NAMES
7691a814370e        ubuntu:14.04        "/bin/bash"         36 hours ago        Exited (0) 21 hours ago                       test
```
export the container
```bash
sudo docker export 7691a814370e > ubuntu.tar #ubuntu.tar is a example
```
import a image file to image
```bash
 docker import ubuntu.tar unbuntu16.04:v1.0 # ubuntu.tar unbuntu16.04:v1.0 is a example
```

Run a image
```bash
sudo docker run -itv /home/smith/workspace/project:/home/mt2523 ubuntu/14.04:linkit_gfx bash
# /home/smith/workspace/project meaning is local directory.
# /home/mt2523 meaning is container directory
# -v: if local directory doest not exist, "-v" is able to remove
```

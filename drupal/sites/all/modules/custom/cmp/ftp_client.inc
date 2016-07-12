<?php

class ftpClient {
  private $ftpConnection;
  private $server;
  private $login;
  private $pass;
  private $secure = false;

  function ftpClient($s, $l, $p, $ss = false) {
    $this->server = $s;
    $this->login = $l;
    $this->pass = $p;
    $this->secure = $ss;
  }

  public function listFiles($directory) {
    return ftp_nlist($this->ftpConnection, $directory);
  }

  public function open() {
    $this->ftpConnection = ftp_connect($this->server);
    ftp_login($this->ftpConnection, $this->login, $this->pass);
  }

  public function close() {
    ftp_close($this->ftpConnection);
  }

  public function get($remoteFile, $localFile) {
    return ftp_get($this->ftpConnection, $localFile, $remoteFile, FTP_BINARY);
  }

  public function put($localFile, $remoteFile) {
    return ftp_put ($this->ftpConnection, $remoteFile, $localFile, FTP_BINARY);
  }

  public function delete($fileName) {
    ftp_delete($this->ftpConnection, $fileName);
  }
}
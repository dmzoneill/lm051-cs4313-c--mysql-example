# CS4313 C++ MySQL Example

<p align="center">
  <img src=".github/logo.png" alt="lm051-cs4313-c--mysql-example logo" width="128" />
</p>

A small C++ GTK application written for the CS4313 Software Engineering
project, from the LM051 Computer Systems degree at the University of Limerick.

## What it does

It opens a gtkmm window with a button. When clicked it fetches a web
page with libcurl and runs a query against a MySQL database, showing the
results. The database settings are hardcoded in the source.

## Tech

- C++ with gtkmm
- libcurl and the MySQL C client library

## Building

Import the Eclipse CDT project, or compile with `g++` against
`gtkmm`, `libcurl` and `mysqlclient`.

## License

Licensed under the Apache License 2.0. See [LICENSE](LICENSE).

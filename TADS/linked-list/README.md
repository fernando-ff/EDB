<div align="center" id="top"> 

  &#xa0;

  <!-- <a href="https://sudoku.netlify.app">Demo</a> -->
</div>

<h1 align="center">List</h1>

<!-- <p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8">

  <img alt="License" src="https://img.shields.io/github/license/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8"> -->

  <!-- <img alt="Github issues" src="https://img.shields.io/github/issues/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8" /> -->

  <!-- <img alt="Github forks" src="https://img.shields.io/github/forks/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8" /> -->

  <!-- <img alt="Github stars" src="https://img.shields.io/github/stars/{{YOUR_GITHUB_USERNAME}}/sudoku?color=56BEB8" /> -->
<!-- </p> -->

<!-- Status -->

<!-- <h4 align="center"> 
	🚧  Sudoku 🚀 Under construction...  🚧
</h4> 

<hr> -->

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0; 
  <a href="#sparkles-features">Features</a> &#xa0; | &#xa0;
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#white_check_mark-requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="#memo-license">License</a> &#xa0; | &#xa0;
  <a href="https://github.com/fernando-ff" target="_blank">Author</a>
</p>

<br>

## :dart: About ##

In computer science, a doubly linked list is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains three fields: two link fields (references to the previous and to the next node in the sequence of nodes) and one data field. The beginning and ending nodes' previous and next links, respectively, point to some kind of terminator, typically a sentinel node or null, to facilitate traversal of the list. If there is only one sentinel node, then the list is circularly linked via the sentinel node. It can be conceptualized as two singly linked lists formed from the same data items, but in opposite sequential orders.

<img src="./assets/1920px-Doubly-linked-list.svg.png" />

The two node links allow traversal of the list in either direction. While adding or removing a node in a doubly linked list requires changing more links than the same operations on a singly linked list, the operations are simpler and potentially more efficient (for nodes other than first nodes) because there is no need to keep track of the previous node during traversal or no need to traverse the list to find the previous node, so that its link can be modified.

## Git Commit Guidelines ##

### Type

Must be one of the following:

- **feat**: A new feature
- **fix**: A bug fix
- **docs**: Documentation only changes
- **style**: Changes that do not affect the meaning of the code (white-space, formatting, missing
  semi-colons, etc)
- **refactor**: A code change that neither fixes a bug nor adds a feature
- **perf**: A code change that improves performance
- **test**: Adding missing or correcting existing tests
- **chore**: Changes to the build process or auxiliary tools and libraries such as documentation
  generation
- **wip**: Work in Progress

**Example:**

```sh
git commit -m "feat: sigaa login form implemented"
```

## :rocket: Technologies ##

The following tools were used in this project:

- [C++](https://www.learncpp.com/)
- [Cmake](https://cmake.org/)
- [Doxygen](https://www.doxygen.nl/manual/starting.html)
- [Valgrind](https://valgrind.org/)
 

## :white_check_mark: Requirements ##

Before starting :checkered_flag:, you need to have [Git](https://git-scm.com) and [Cmake](https://cmake.org/) installed.

## :checkered_flag: Starting ##

```bash

# to compile
$ cmake -S source -Bbuild
$ cmake --build build

# Run the project
$ ./build/run_tests 

# Remember to execute the commands in the root
```

## :memo: License ##

This project is under license from SELAN. For more details, enter in contact with [SELAN](https://sigaa.ufrn.br/sigaa/public/docente/portal.jsf?siape=2497950).


Made with :heart: by <a href="https://github.com/fernando-ff" target="_blank">Fernando Ferreira</a>

&#xa0;

<a href="#top">Back to top</a>
# Embedded Intent Recognizer

Naive intent recognition command line tool.


## Repository

[Repository](https://github.com/gregorgrisza/eir)

```
git clone git@github.com:gregorgrisza/eir.git
```
## Description
### What does it do?

Program intends to recognize User intention by entered sentence.

### How?

Program has own database of sentences with defined corresponding intent.

It's naive recognition based on bags of cleaned/sanitized words with cross calculated ranking value for each word on several levels.
which introduces some limitation when there is not enough learn data, or there is too much learned data, e.g. in situation where sentence is long and consists
many words which appear in other sentences as well, but with different meaning (intention expressed).

### Limitations

Algorithm of recognition is very naive and doesn't have:

- stemming, lemmatization
- language specific recognition
- semantics handling
- generic entities recognition
- ...


## Usage

```
cd ${ProjectRoot}
./build/src/eir
```
---
**NOTE**

Program needs to be executed from directory level where is accessible relatively `data/train_data.json` file from.

---


### User interaction

During program run User needs to enter sentence and confirm with `Enter` key.

Confirmation of empty line finishes program run.

Interruption using Ctrl^C also finishes program, but return code is not successful.

```
What is the weather like today? => Prints (Intent: Get Weather)
What is the weather like in Paris today? => Prints (Intent: Get Weather City)
Tell me an interesting fact. => Prints (Intent: Get Fact)

Bye Bye!
```

### Learning

Learn process is done at runtime and is based on learn data definition.

Learn data definition is database of examples with defined intentions information as follows:

```
    {
        "input" :
            [
                "What is the weather like [today](Date)?",
                "What is the weather like in [Paris](City) [today](Date)?"
            ],
        "intent" : "Get Weather"
    },
```

#### `input` section

`input` section defines list od possible sentences with defined entities.

Each sentence will be calculated as probe by Analyzer.

Each word will be calculated and stored in bags of words for each `intent`

#### Entities definition

Entities are defined in `input` section in each sentence/item.

Each entity has structure: `[word](Type)`

`word` is possible value which will be recognized as being of type `Type`, where each `Type` is mapped to implementation/class.

#### `intent` section

`intent` defines intent id matched in code and implementing intent behavior. 

## Setup development environment

### Necessary Dependencies
1. A C++ compiler that supports C++17.
See [cppreference.com](https://en.cppreference.com/w/cpp/compiler_support)
to see which features are supported by each compiler.
The following compilers should work:

  * [gcc 7+](https://gcc.gnu.org/)
	<details>
	<summary>Install command</summary>

	- Debian/Ubuntu:

			sudo apt install build-essential

	</details>

  * [clang 6+](https://clang.llvm.org/)
	<details>
	<summary>Install command</summary>

	- Debian/Ubuntu:

			bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

	</details>

1. [CMake 3.15+](https://cmake.org/)
	<details>
	<summary>Install Command</summary>

	- Debian/Ubuntu:

			sudo apt-get install cmake

	- Windows:

			choco install cmake -y

	- MacOS:

			brew install cmake

	</details>

### Optional Dependencies
#### C++ Tools
  * [Doxygen](http://doxygen.nl/)
	<details>
	<summary>Install Command</summary>

	- Debian/Ubuntu:

			sudo apt-get install doxygen
			sudo apt-get install graphviz

	</details>


  * [ccache](https://ccache.dev/)
	<details>
	<summary>Install Command</summary>

	- Debian/Ubuntu:

			sudo apt-get install ccache

	</details>


  * [Cppcheck](http://cppcheck.sourceforge.net/)
	<details>
	<summary>Install Command</summary>

	- Debian/Ubuntu:

			sudo apt-get install cppcheck


## Build Instructions

A full build has different steps:
1) Specifying the compiler using environment variables
2) Configuring the project
3) Building the project

For the subsequent builds, in case you change the source code, you only need to repeat the last step.

### (1) Specify the compiler using environment variables

By default (if you don't set environment variables `CC` and `CXX`), the system default compiler will be used.

Conan and CMake use the environment variables CC and CXX to decide which compiler to use. So to avoid the conflict issues only specify the compilers using these variables.

CMake will detect which compiler was used to build each of the Conan targets. If you build all of your Conan targets with one compiler, and then build your CMake targets with a different compiler, the project may fail to build.

<details>
<summary>Commands for setting the compilers </summary>

- Debian/Ubuntu/MacOS:

	Set your desired compiler (`clang`, `gcc`, etc):

	- Temporarily (only for the current shell)

		Run one of the followings in the terminal:

		- clang

				CC=clang CXX=clang++

		- gcc

				CC=gcc CXX=g++

	- Permanent:

		Open `~/.bashrc` using your text editor:

			gedit ~/.bashrc

		Add `CC` and `CXX` to point to the compilers:

			export CC=clang
			export CXX=clang++

		Save and close the file.

  - Temporarily (only for the current shell):

			$Env:CC="clang.exe"
			$Env:CXX="clang++.exe"

</details>

### (2) Configure your build

To configure the project, you could use `cmake`

    cmake -S . -B ./build

Cmake will automatically create the `./build` folder if it does not exist, and it wil configure the project.

or

	mkdir build && cd build && cmake ..


## Testing
See [Catch2 tutorial](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md)

## TODOs

1. Organize code into namespaces
2. Refactor Preprocessor into Chain of responsibility pattern
3. Add type names to increase readability, mostly for learn data type, e.g. `std::map<std::string, std::map<std::string, int>>` should be 
more like e.g. `std::map<Word, CountForIntent>`
4. Implement key words handling and acceptance threshold for assigning to Intent.
Problem exist in recognizing by words which exist in more than one Intent, so are not so important, 
or even doesn't have meaning, e.g. "what", "is", "the", "Tell". In this case, if there are only 
those words entered, Intent cannot be chosen. This problem might be also resolved by comparing 
importance of words and checking coverage of words for particular sentence.
4. Update comments.
5. Exceptions handling, e.g. for currupted learn data in JSON.

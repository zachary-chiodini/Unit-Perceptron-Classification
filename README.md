<h1>The Perceptron Unit</h1>
    <p align="justify">
        This page serves as a learning tool to assist in understanding a single perceptron unit and its applications,
        outside of multilayered neural networks, with C++ and Python.
        Multilayered neural networks are the talk of the town.
        However, let's not get ahead of ourselves.
        Instead, let's start with a discussion of the units within the network, perceptrons.
        Once the perceptron is understood, a neural network can follow.
    </p>
    <p align="justify">
        This page is not meant to be an exhaustive source of perceptron knowledge.
        It is meant to be breif and straight to the point.
        Additionally, this page may serve as a breif introductory comparison between C++ and Python.
    </p>
    <h1 style="color:#02FF02">Mathematical Model</h1>
    <p align="justify">
        Let's describe a perceptron by a function f.
        The mathematical model for a typical perceptron is a simple step function (1), where τ is called the threshold.
        The function can be rewritten so that the inequalities are set to zero (2),
        where the bias b = -τ.
        This is called a boolean function, because its output can only be either 1 or 0, which corresponds to true or false.
        A graph of the step function is shown to the right. It's no coincidence that it looks like a step.
    </p>
    <table align="center" style="border-spacing:0px">
        <tr>
            <td>
                <table align="center" style="border-spacing:0px">
                    <tr><td><p align="center"><img style="width:50%; height:50%" src="step_function.png" /><p></td></tr>
                    <tr><td><p align="center"><img style="width:58%; height:58%" src="step_function_2.png" /><p></td></tr>
                </table>
            </td>
            <td><img style="width:75%; height:75%" ; src="step_graph.png" /></td>
        </tr>
    </table>
    <p align="justify">
        The perceptron is really that simple, but the function is hiding some important details.
        The input for the perceptron is a weighted sum, which is given by the dot product of two vectors:
        an inpute vector x and the network vector ω, each having n components (3).
        The input vector contains the data to be interpreted by the perceptron.
        The network vector contains the weight or coefficient for each input vector component.
    </p>
    <p align="center"><img style="width:27%; height:27%" src="step_function_3.png" /></p>
    <p align="justify">
        To make things more compact, we can increase the size of both vectors to n + 1 and
        force the first component of the input vector to be -1
        and the first component of the network vector to be the threshold τ,
        so that the first product in the sum is -τ.
        Alternatively, we can force the first component of the input vector to be 1
        and the first component of the network vector to be the bias b (4).
    </p>
    <p align="center"><img style="width:50%; height:50%" src="step_function_4.png" /></p>
    <p align="justify">
        A perceptron unit with specified weights can be used to model simple decision making.
        For example, a perceptron unit could be used to determine whether or not one should get up in the morning.
        The input vector could hold boolean values for
        good wheather, job duties, errands to run, hobbies to do, friends to visit, fitness goals, hunger and poor hygeine,
        each being 0 or 1 for true or false.
        The weights of which correspond to their importance.
        The bias could represent one's motivation.
        Since b = -τ, a greater bias lowers the threshold of the perceptron.
        After feeding the data into the perceptron, if it outputs a 1, you should get up. Otherwise, take it easy.
    </p>
    <h1 style="color:#02FF02">In Python and C++</h1>
    <p align="justify">
        Below is the code for a perceptron in C++ and Python.
        The C++ program must explicitly define all of the data types being used, whereas in Python, datatypes are assumed based on their context.
        The Python function can accept multiple data types as it is written, even while the data types of its parameters are explicitly defined.
        The C++ function can only accept the specific data types that are defined as its parameters.
        Multiple data types can only be accepted if explicitly stated.
        A lot of what is explicitly defined in C++ is done "behind the scenes" in Python.
        However, there is still a lot going on behind the scenes in C++, as we shall see.
        In general, C++ syntax is bulkier than Python, but allows for more control over the program.
        Python's compact and easy-to-use syntax speeds up development time, but at a cost to its performace.
        C++ is known for its fast performance, but will take longer to develop.
        Nonetheless, moving forward, it will be easy to see that the two languages share a lot in common.
    </p>
    <p align="justify">
        The input and network vectors are implemented as dynamic arrays of floating point numbers,
        so that the functions can accept arrays of any size containing any number on the real number line.
        Each array is passed as a reference to the original array, instead of passing a copy of it.
        This is done automatically in Python and explicitly stated in C++ by the ampersand symbol proceeding each keyword.
        These arrays remain constant throughout the dot product operation, which is also explicitly stated in C++.
        Constants cannot be explicitly defined in Python.
    </p>
    <p align="justify">
        The C++ program shows more details of the operation.
        An iterator is declared for each array, which will be used to refer to a particular element within the array.
        The iterators are defined as constant because they will not be used to change any element to which they refer.
        The iterators will be used to loop through the contents of the two arrays simultaneously.
    </p>
    <p align="justify">
        The initialization statement of the for loop assigns each declared iterator to an iterator
        that refers to the first element of either array, using the begin() member function.
        This is executed only once.
        The condition for executing the code block checks whether one of the iterators are equal to the iterator
        that is one past the last element of the referenced array, which is given by the end() member function.
        If they are equal, the loop will break.
        The update statement of the loop increments each iterator to the next in the array and executes after every iteration.
        Since each iterator is a reference to a particular element and not the value itself,
        they are dereferenced by an asterix and multiplied.
    </p>
    <p align="justify">
        The zip function returns a special iterable called a zip object but behaves in a similar way.
        Since we are iterating over both arrays at the same time, the asymptotic time complexity is linear.
    </p>
    <table align="center" style="border-spacing:0px">
        <tr>
            <td><h2 style="color:#02FF02; text-align:center">Python</h2></td>
            <td><h2 style="color:#02FF02; text-align:center ">C++</h2></td>
        </tr>
        <tr>
            <td>
                <div style="height:200px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%">1
2
3
4
5
6</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">typing</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;<span style="color:#4ec9b0;">List</span>&nbsp;<span style="color:#57a64a;">#&nbsp;dynamic&nbsp;array</span>
<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">b</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">b</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;xi<span style="color:#b4b4b4;">,</span>&nbsp;wi&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">zip</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;xi<span style="color:#b4b4b4;">*</span>wi
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">)</span></pre>
                            </td>
                        </tr>
                    </table>
                </div>
            </td>
            <td>
                <div style="height:200px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%">1
2
3
4
5
6
7
8
9
10
11
12
13</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">vector</span><span style="color:#e8c9bb;">&gt;</span>&nbsp;<span style="color:#57a64a;">//&nbsp;dynamic&nbsp;array</span>
<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#dcdcaa;">perceptron</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">b</span>&nbsp;
<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">b</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;::</span><span style="color:#4ec9b0;">const_iterator</span>&nbsp;<span style="color:#9cdcfe;">xi</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">wi</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">xi</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">wi</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#9cdcfe;">xi</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">xi</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">wi</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b4b4b4;">*</span><span style="color:#9cdcfe;">xi</span>&nbsp;<span style="color:#b4b4b4;">*</span>&nbsp;<span style="color:#b4b4b4;">*</span><span style="color:#9cdcfe;">wi</span><span style="color:#b4b4b4;">;</span>
<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">);</span>
<span style="color:#b4b4b4;">}</span></pre>
                            </td>
                        </tr>
                    </table>
            </td>
        </tr>
    </table>
    </div>
    </td></tr>
    </table>
    <p align="justify">
        The dot product operation can also be achieved by accessing the elements in each array by index.
        This is also done in linear time, because the data in an array is allocated contiguously in memory.
        The memory address of an element in an array is the address of the first element plus the product of its index
        and the number of bytes of the array datatype.
        This way, when accessing an element in the array, the compiler only needs to access the memory location of the first element to find
        the location of any other element within it. This is done in constant time regardless of the size of the array.
    </p>
    <table align="center" style="border-spacing:0px">
        <tr>
            <td><h2 style="color:#02FF02; text-align:center">Python</h2></td>
            <td><h2 style="color:#02FF02; text-align:center ">C++</h2></td>
        </tr>
        <tr>
            <td>
                <div style="height:200px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%">1
2
3
4
5
6</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">typing</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;<span style="color:#4ec9b0;">List</span>&nbsp;<span style="color:#57a64a;">#&nbsp;dynamic&nbsp;array</span>
<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">b</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">b</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;i&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">range</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#c8c8c8;">len</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;i&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">*</span><span style="color:#b4b4b4;">w</span><span style="color:#b4b4b4;">[</span>&nbsp;i&nbsp;<span style="color:#b4b4b4;">]</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">)</span></pre>
                            </td>
                        </tr>
                    </table>
                </div>
            </td>
            <td>
                <div style="height:200px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%">1
2
3
4
5
6
7
8
9
10
11
12</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">vector</span><span style="color:#e8c9bb;">&gt;</span>&nbsp;<span style="color:#57a64a;">//&nbsp;dynamic&nbsp;array</span>
<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#dcdcaa;">perceptron</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">b</span>
<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">b</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">*</span><span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">);</span>
<span style="color:#b4b4b4;">}</span></pre>
                            </td>
                        </tr>
                    </table>
            </td>
        </tr>
    </table>
    </div>
    </td></tr>
    </table>
    <h1 style="color:#02FF02">The Perceptron Training Algorithm and Classification</h1>
    <p align="justify">
        A more interesting application uses the perceptron training algorithm.
        This enables the perceptron to compute the correct network given a training set,
        which is a set of input vectors and their expected outputs or target values.
        If a large enough representative sample of input vectors are in the training set,
        the network weights computed by the training algorithm
        can then be used to classify all the data from which the training set was sampled,
        as long as the data is linearly separable.
    </p>
    <p align="justify">
        The condition that the data must be linearly separable comes from the mathematical model of the perceptron.
        In 2 dimensions, given an input vector ( 1, x, y ) and a network vector ( b, ω1, ω2 ), the dot product is b + ω1x + ω2y.
        Replacing the inequalities with an equals sign and solving for y creates a line (5).
    </p>
    <p align="center"><img style="width:18%; height:18%" src="line.png" /></p>
    <p align="justify">
        Therefore, the perceptron can only classify data that can be separated by this line.
        This is also true for n dimensions in which the line is a hyperplane.
    </p>
    <p align="justify">
        The training algorithm is as follows:
    </p>
    <p align="center"><img style="width:60%; height:60%" src="training_algorithm.png" /></p>
    <p align="justify">
        This algorithm is slighly different than other perceptron learning algorithms in that the output vector
        is conditioned to exactly equal the target vector before stopping the loop.
        This is always possible with the appropriate weights, as long as the data is linearly separable.
        If the data is not linearly separable, an infinite loop may ensue.
    </p>
    <h1 style="color:#02FF02">Network Class</h1>
    <p align="justify">
        A class Network is created in Python and C++ to provide everything we need to start training and testing the perceptron.
        The two programs are nearly identical and easy to compare and contrast.
        The Network class is essentially an API that a user can apply to any appropriate data set.
    </p>
    <table align="center" style="border-spacing:0px">
        <tr>
            <td><h2 style="color:#02FF02; text-align:center">Python</h2></td>
            <td><h2 style="color:#02FF02; text-align:center ">C++</h2></td>
        </tr>
        <tr>
            <td>
                <div style="height:300px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;line-height: 125%;font-size:13px;color:gainsboro;background:#002240;"><span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">typing</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;<span style="color:#4ec9b0;">List</span>&nbsp;<span style="color:#57a64a;">#&nbsp;dynamic&nbsp;array</span>
<span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">random</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;random
&nbsp;
<span style="color:#569cd6;">class</span>&nbsp;<span style="color:#4ec9b0;">Network</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#4ab667;">&#39;&#39;&#39;&nbsp;Unit&nbsp;Perceptron&nbsp;Network&nbsp;&#39;&#39;&#39;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">__init__</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__results&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[]</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[]</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">__update</span><span style="color:#b4b4b4;">(</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">xi</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">#&nbsp;ith&nbsp;input&nbsp;array</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">#&nbsp;current&nbsp;network</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">ti</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">ai</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">#&nbsp;target,&nbsp;output&nbsp;of&nbsp;ith&nbsp;array</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">r</span>&nbsp;&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">#&nbsp;learning&nbsp;rate</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b4b4b4;">r</span><span style="color:#b4b4b4;">*</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">ti</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#b4b4b4;">ai</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;j&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">range</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#c8c8c8;">len</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">xi</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">w</span><span style="color:#b4b4b4;">[</span>&nbsp;j&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b4b4b4;">r</span><span style="color:#b4b4b4;">*</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">ti</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#b4b4b4;">ai</span>&nbsp;<span style="color:#b4b4b4;">)</span><span style="color:#b4b4b4;">*</span><span style="color:#b4b4b4;">xi</span><span style="color:#b4b4b4;">[</span>&nbsp;j&nbsp;<span style="color:#b4b4b4;">]</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#b4b4b4;">w</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">__output</span><span style="color:#b4b4b4;">(</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">#&nbsp;i&nbsp;input&nbsp;arrays</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">#&nbsp;current&nbsp;network</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">xi</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#569cd6;">for</span>&nbsp;<span style="color:#b4b4b4;">xi</span>&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">]</span>
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">b</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">b</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;xi<span style="color:#b4b4b4;">,</span>&nbsp;wi&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">zip</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">w</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;xi<span style="color:#b4b4b4;">*</span>wi
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;dot_product&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">train</span><span style="color:#b4b4b4;">(</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">#&nbsp;i&nbsp;input&nbsp;arrays</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">t</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">#&nbsp;i&nbsp;outputs</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">b</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">r</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#70b0e0;">None</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">b</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;w&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#b5cea8;">0.5</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;random<span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#569cd6;">for</span>&nbsp;<span style="color:#b4b4b4;">_</span>&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">]</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">while</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">__output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;w&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#b4b4b4;">t</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;xi<span style="color:#b4b4b4;">,</span>&nbsp;ti&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">zip</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">t</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ai&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;xi<span style="color:#b4b4b4;">,</span>&nbsp;w<span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;w&nbsp;&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">__update</span><span style="color:#b4b4b4;">(</span>&nbsp;xi<span style="color:#b4b4b4;">,</span>&nbsp;w<span style="color:#b4b4b4;">,</span>&nbsp;ti<span style="color:#b4b4b4;">,</span>&nbsp;ai<span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">r</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;w
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">test</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">x</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#70b0e0;">None</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">assert</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network<span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#d69d85;">&#39;Network&nbsp;must&nbsp;be&nbsp;trained.&#39;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__results&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">__output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">get_output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__results
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">show_output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#70b0e0;">None</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;Unit&nbsp;output:&#39;</span><span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&nbsp;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;ai&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__results&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;ai<span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&nbsp;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">()</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">get_network</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">+</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network
&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">show_network</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#70b0e0;">None</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;Unit&nbsp;network:&#39;</span><span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&nbsp;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__bias<span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&nbsp;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">for</span>&nbsp;wi&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#b4b4b4;">self</span><span style="color:#b4b4b4;">.</span>__network&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;wi<span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&nbsp;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">()</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span></pre>
                            </td>
                        </tr>
                    </table>
                </div>
            </td>
            <td>
                <div style="height:300px; width:600px; overflow:auto; font-family:Consolas;font-size:13px">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">vector</span><span style="color:#e8c9bb;">&gt;</span>&nbsp;<span style="color:#57a64a;">//&nbsp;dynamic&nbsp;array</span>
<span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">assert.h</span><span style="color:#e8c9bb;">&gt;</span>
<span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">random</span><span style="color:#e8c9bb;">&gt;</span>
<span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">iostream</span><span style="color:#e8c9bb;">&gt;</span>
 
<span style="color:#569cd6;">class</span>&nbsp;<span style="color:#4ec9b0;">Network</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">/*&nbsp;Unit&nbsp;Perceptron&nbsp;Network&nbsp;*/</span>
<span style="color:#569cd6;">private</span><span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0.0</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dadada;">results</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">{};</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dadada;">network</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">{};</span>
 
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dcdcaa;">update</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">xi</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">//&nbsp;ith&nbsp;unput&nbsp;array</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;current&nbsp;network</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">ti</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;target&nbsp;value</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">ai</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;output&nbsp;of&nbsp;ith&nbsp;array</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">r</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;learning&nbsp;rate</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#9a9a9a;">r</span><span style="color:#b4b4b4;">*(</span>&nbsp;<span style="color:#9a9a9a;">ti</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#9a9a9a;">ai</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#9a9a9a;">r</span><span style="color:#b4b4b4;">*(</span>&nbsp;<span style="color:#9a9a9a;">ti</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#9a9a9a;">ai</span>&nbsp;<span style="color:#b4b4b4;">)*</span><span style="color:#9a9a9a;">xi</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dcdcaa;">output</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">//&nbsp;i&nbsp;input&nbsp;arrays</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">w</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;current&nbsp;netork</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">out</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">out</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#dcdcaa;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#9cdcfe;">out</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
<span style="color:#569cd6;">public</span><span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#dcdcaa;">perceptron</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">b</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">b</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">*</span><span style="color:#9a9a9a;">w</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">dot_product</span>&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">void</span>&nbsp;<span style="color:#dcdcaa;">train</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#57a64a;">//&nbsp;i&nbsp;input&nbsp;vectors</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">t</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;i&nbsp;outputs</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#9a9a9a;">b</span><span style="color:#b4b4b4;">,</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;bias</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">float</span>&nbsp;<span style="color:#9a9a9a;">r</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#57a64a;">//&nbsp;learning&nbsp;rate</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9a9a9a;">b</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">random_device</span>&nbsp;<span style="color:#9cdcfe;">random</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#57a64a;">//&nbsp;int&nbsp;random&nbsp;number&nbsp;generator</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">uniform_real_distribution</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">uniform</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">-</span><span style="color:#b5cea8;">0.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">0.5</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">w</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">w</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">uniform</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">random</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">while</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#dcdcaa;">output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">w</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#9a9a9a;">t</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">ai</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">perceptron</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">w</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">update</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">w</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">t</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">ai</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">r</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#dadada;">network</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9cdcfe;">w</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">void</span>&nbsp;<span style="color:#dcdcaa;">test</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">x</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#beb7ff;">assert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">!</span><span style="color:#dadada;">network</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">empty</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#e8c9bb;">&#39;</span><span style="color:#d69d85;">Network&nbsp;must&nbsp;be&nbsp;trained.</span><span style="color:#e8c9bb;">&#39;</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#dadada;">results</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">output</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">x</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#dadada;">network</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dcdcaa;">get_output</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#dadada;">results</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">void</span>&nbsp;<span style="color:#dcdcaa;">show_output</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">Unit&nbsp;output:&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#dadada;">results</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#dadada;">results</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#dcdcaa;">endl</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#dcdcaa;">get_network</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">net</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dadada;">network</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">net</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">insert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">net</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#9cdcfe;">net</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">void</span>&nbsp;<span style="color:#dcdcaa;">show_network</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">Unit&nbsp;network:&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#dadada;">bias</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">!=</span>&nbsp;<span style="color:#dadada;">network</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">();</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#dadada;">network</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#dcdcaa;">endl</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
<span style="color:#b4b4b4;">};</span></pre>
                            </td>
                        </tr>
                    </table>
            </td>
        </tr>
    </table>
    </div>
    </td></tr>
    </table>
    <h1 style="color:#02FF02">Example</h1>
    <p align="justify">
        To demonstrate, the iris dataset will be used. It contains measurements of iris flowers of three different species.
        The perceptron will be trained to differentiate between the iris setosa and the others (iris virginica and iris versicolor)
        from sepal and petal length measurements. The training process is performed on the complete data set and animated below.
        If your browser does not support animated png files, please switch to one that does.
        The aforementioned line is updated with the updated weights each time the for loop completes.
        The algorithm goes through the data multiple times.
        The line stops updating when the output equals the target values.
        After the training algorithm completes,
        everything to the left of the line gives an output of 1, and everything to the right gives an output of 0.
    </p>
    <p align="center"><img style="width:25%; height:25%" src="perceptron_learning.png" /></p>
    <p align="justify">
        The idea is that the final weights used to construct the line that separates the iris setosa species from the others
        can now be applied to a new sepal and petal length measurement of an unknown iris species to classify it.
    </p>
    <h1 style="color:#02FF02">Try It</h1>
    <p align="justify">
        To simulate this idea, the program below takes a randomized sample from the setosa and others data to train the preceptron.
        The size of each sample is specified by the user's input.
        Then, the network that was computed using the samples is applied to the full data set.
        The Setosa data should ouput ones, while the other data should output zeros.
        Note that the network changes with varying accuracy each time you run the program, when lower sample sizes are used.
        Obviously, a larger sample size will yield more accurate results. Give it a try.
        Visual Studio can be used to run both C++ and Python.
    </p>
    <table align="center" style="border-spacing:0px">
        <tr>
            <td><h2 style="color:#02FF02; text-align:center">Python</h2></td>
            <td><h2 style="color:#02FF02; text-align:center ">C++</h2></td>
        </tr>
        <tr>
            <td>
                <div style="height:300px; width:600px; overflow:auto; font-family:courier">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;line-height: 125%;font-size:13px;color:gainsboro;background:#002240;"><span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">typing</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;<span style="color:#4ec9b0;">List</span>
<span style="color:#569cd6;">from</span>&nbsp;<span style="color:#e090d0;">random</span>&nbsp;<span style="color:#569cd6;">import</span>&nbsp;randint
&nbsp;
setosa&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span>
<span style="color:#b4b4b4;">]</span>
others&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">3.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">]</span>
<span style="color:#b4b4b4;">]</span>
<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">data</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">]</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">m</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">List</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#4ec9b0;">float</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;samp&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[]</span>
&nbsp;&nbsp;&nbsp;&nbsp;i<span style="color:#b4b4b4;">,</span>&nbsp;js&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">[]</span>
&nbsp;&nbsp;&nbsp;&nbsp;n&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#c8c8c8;">len</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">data</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">while</span>&nbsp;i&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#b4b4b4;">m</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;randint<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">,</span>&nbsp;n&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#b5cea8;">1</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">if</span>&nbsp;j&nbsp;<span style="color:#569cd6;">not</span>&nbsp;<span style="color:#569cd6;">in</span>&nbsp;js&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b5cea8;">1</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;js<span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">append</span><span style="color:#b4b4b4;">(</span>&nbsp;j&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;samp<span style="color:#b4b4b4;">.</span><span style="color:#c8c8c8;">append</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">data</span><span style="color:#b4b4b4;">[</span>&nbsp;j&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;samp
&nbsp;
<span style="color:#569cd6;">def</span>&nbsp;<span style="color:#c8c8c8;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">s</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">str</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mn</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mx</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">-&gt;</span>&nbsp;<span style="color:#4ec9b0;">int</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;Enter&nbsp;the&nbsp;number&nbsp;of&nbsp;data&nbsp;points&nbsp;to&nbsp;sample&nbsp;for&nbsp;&#39;</span><span style="color:#b4b4b4;">,</span>&nbsp;end&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#d69d85;">&#39;&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;n&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#c8c8c8;">input</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;{}:&nbsp;&#39;</span><span style="color:#b4b4b4;">.</span>format<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">s</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">try</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#4ec9b0;">int</span><span style="color:#b4b4b4;">(</span>&nbsp;n&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">except</span>&nbsp;<span style="color:#b4b4b4;">:</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;Please&nbsp;choose&nbsp;an&nbsp;integer&nbsp;value.&#39;</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#c8c8c8;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mn</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mx</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">if</span>&nbsp;n&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#b4b4b4;">mn</span>&nbsp;<span style="color:#569cd6;">or</span>&nbsp;n&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#b4b4b4;">mx</span>&nbsp;<span style="color:#b4b4b4;">:</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">print</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;{}&nbsp;contains&nbsp;{}&nbsp;to&nbsp;{}&nbsp;data&nbsp;points.&#39;</span><span style="color:#b4b4b4;">.</span>format<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mn</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mx</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;<span style="color:#c8c8c8;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b4b4b4;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mn</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b4b4b4;">mx</span>&nbsp;<span style="color:#b4b4b4;">)</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">return</span>&nbsp;n
 
set_n&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#c8c8c8;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;setosa&#39;</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">50</span>&nbsp;<span style="color:#b4b4b4;">)</span>
oth_n&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#c8c8c8;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#d69d85;">&#39;others&#39;</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">100</span>&nbsp;<span style="color:#b4b4b4;">)</span>
samples&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#c8c8c8;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;setosa<span style="color:#b4b4b4;">,</span>&nbsp;set_n&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">+</span>&nbsp;<span style="color:#c8c8c8;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;others<span style="color:#b4b4b4;">,</span>&nbsp;oth_n&nbsp;<span style="color:#b4b4b4;">)</span>
targets&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#b5cea8;">1</span>&nbsp;<span style="color:#569cd6;">for</span>&nbsp;<span style="color:#b4b4b4;">i</span>&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">range</span><span style="color:#b4b4b4;">(</span>&nbsp;set_n&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">+</span>&nbsp;<span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#569cd6;">for</span>&nbsp;<span style="color:#b4b4b4;">i</span>&nbsp;<span style="color:#569cd6;">in</span>&nbsp;<span style="color:#4ec9b0;">range</span><span style="color:#b4b4b4;">(</span>&nbsp;oth_n&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">]</span>
network&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;Network<span style="color:#b4b4b4;">()</span>
network<span style="color:#b4b4b4;">.</span>train<span style="color:#b4b4b4;">(</span>&nbsp;samples<span style="color:#b4b4b4;">,</span>&nbsp;targets<span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">0.01</span>&nbsp;<span style="color:#b4b4b4;">)</span>
network<span style="color:#b4b4b4;">.</span>test<span style="color:#b4b4b4;">(</span>&nbsp;setosa&nbsp;<span style="color:#b4b4b4;">+</span>&nbsp;others&nbsp;<span style="color:#b4b4b4;">)</span>
network<span style="color:#b4b4b4;">.</span>show_network<span style="color:#b4b4b4;">()</span>
network<span style="color:#b4b4b4;">.</span>show_output<span style="color:#b4b4b4;">()</span></pre>
                            </td>
                        </tr>
                    </table>
                </div>
            </td>
            <td>
                <div style="height:300px; width:600px; overflow:auto; font-family:Consolas;font-size:13px">
                    <table class="table">
                        <tr>
                            <td>
                                <div class="linenodiv" style="background-color: #454545; padding-right: 10px">
                                    <pre style="line-height: 125%"> 1
 2
 3
 4
 5
 6
 7
 8
 9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111</pre>
                                </div>
                            </td>
                            <td class="code">
                                <pre style="font-family:Consolas;font-size:13px;line-height: 125%;color:gainsboro;background:#002240;"><span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">iostream</span><span style="color:#e8c9bb;">&gt;</span>
<span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">vector</span><span style="color:#e8c9bb;">&gt;</span>
<span style="color:#9b9b9b;">#include</span>&nbsp;<span style="color:#e8c9bb;">&lt;</span><span style="color:#d69d85;">random</span><span style="color:#e8c9bb;">&gt;</span>
 
<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#dcdcaa;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;&amp;</span>&nbsp;<span style="color:#9a9a9a;">data</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">n</span>&nbsp;
<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">js</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">samp</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">random_device</span>&nbsp;<span style="color:#9cdcfe;">random</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#57a64a;">//&nbsp;int&nbsp;random&nbsp;number&nbsp;generator</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">uniform_int_distribution</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">uniform</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">data</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">size</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">-</span>&nbsp;<span style="color:#b5cea8;">1</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">while</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">n</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#9cdcfe;">uniform</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">random</span>&nbsp;<span style="color:#b4b4b4;">)</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">if</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#dcdcaa;">count</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">js</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">js</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">==</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">js</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">samp</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">data</span><span style="color:#b4b4b4;">[</span>&nbsp;<span style="color:#9cdcfe;">j</span>&nbsp;<span style="color:#b4b4b4;">]</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">+=</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#9cdcfe;">samp</span><span style="color:#b4b4b4;">;</span>
<span style="color:#b4b4b4;">}</span>
 
<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#dcdcaa;">choose_n</span><span style="color:#b4b4b4;">(</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">string</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">mn</span><span style="color:#b4b4b4;">,</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">const</span>&nbsp;<span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&amp;</span>&nbsp;<span style="color:#9a9a9a;">mx</span>
<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">Enter&nbsp;the&nbsp;number&nbsp;of&nbsp;data&nbsp;points&nbsp;to&nbsp;sample&nbsp;for&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#9a9a9a;">s</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#dcdcaa;">endl</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">n</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cin</span>&nbsp;<span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">n</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">if</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cin</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">fail</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">Please&nbsp;choose&nbsp;an&nbsp;integer&nbsp;value.</span><span style="color:#e8c9bb;">&quot;</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#dcdcaa;">endl</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cin</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">clear</span><span style="color:#b4b4b4;">();</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cin</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">ignore</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">numeric_limits</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">streamsize</span><span style="color:#b4b4b4;">&gt;::</span><span style="color:#dcdcaa;">max</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#e8c9bb;">&#39;</span><span style="color:#ffd68f;">\n</span><span style="color:#e8c9bb;">&#39;</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#dcdcaa;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">mn</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">mx</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">if</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">n</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9a9a9a;">mn</span>&nbsp;<span style="color:#b4b4b4;">or</span>&nbsp;n&nbsp;<span style="color:#b4b4b4;">&gt;</span>&nbsp;mx&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#9a9a9a;">s</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;contains&nbsp;</span><span style="color:#e8c9bb;">&quot;</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#9a9a9a;">mn</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;to&nbsp;</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#c8c8c8;">cout</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#9a9a9a;">mx</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">&nbsp;data&nbsp;points.</span><span style="color:#e8c9bb;">&quot;</span>&nbsp;<span style="color:#b4b4b4;">&lt;&lt;</span>&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#dcdcaa;">endl</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#dcdcaa;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9a9a9a;">s</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">mn</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9a9a9a;">mx</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#9cdcfe;">n</span><span style="color:#b4b4b4;">;</span>
<span style="color:#b4b4b4;">}</span>
 
<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#dcdcaa;">main</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">setosa</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">1.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">};</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">others</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">3.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.3</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.2</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">6.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">7.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.5</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.4</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">4.8</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.0</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.6</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.9</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.8</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.7</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.7</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.0</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.3</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.2</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.5</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.4</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">6.2</span><span style="color:#b4b4b4;">},</span>&nbsp;<span style="color:#b4b4b4;">{</span><span style="color:#b5cea8;">5.1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">5.9</span><span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">};</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">set_n</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">setosa</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">50</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">oth_n</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">choose_n</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#e8c9bb;">&quot;</span><span style="color:#d69d85;">others</span><span style="color:#e8c9bb;">&quot;</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">100</span>&nbsp;<span style="color:#b4b4b4;">);</span>
 
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">sample1</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">setosa</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">set_n</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">sample2</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#dcdcaa;">sample</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">others</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">oth_n</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">insert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">sample1</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">sample1</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#b4b4b4;">().</span><span style="color:#dcdcaa;">swap</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">sample1</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">insert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">sample2</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">sample2</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#b4b4b4;">().</span><span style="color:#dcdcaa;">swap</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">sample2</span>&nbsp;<span style="color:#b4b4b4;">);</span>
 
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">int</span><span style="color:#b4b4b4;">&gt;</span>&nbsp;<span style="color:#9cdcfe;">targets</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9cdcfe;">set_n</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">targets</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b5cea8;">1</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">for</span>&nbsp;<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#569cd6;">int</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">&lt;</span>&nbsp;<span style="color:#9cdcfe;">oth_n</span><span style="color:#b4b4b4;">;</span>&nbsp;<span style="color:#b4b4b4;">++</span><span style="color:#9cdcfe;">i</span>&nbsp;<span style="color:#b4b4b4;">)</span>&nbsp;<span style="color:#b4b4b4;">{</span>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">targets</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">push_back</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#b5cea8;">0</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#b4b4b4;">}</span>
 
&nbsp;&nbsp;&nbsp;&nbsp;Network&nbsp;<span style="color:#9cdcfe;">network</span>&nbsp;<span style="color:#b4b4b4;">=</span>&nbsp;Network<span style="color:#b4b4b4;">();</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">network</span><span style="color:#b4b4b4;">.</span>train<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">samples</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#9cdcfe;">targets</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">1</span><span style="color:#b4b4b4;">,</span>&nbsp;<span style="color:#b5cea8;">0.01</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#c8c8c8;">std</span><span style="color:#b4b4b4;">::</span><span style="color:#4ec9b0;">vector</span><span style="color:#b4b4b4;">&lt;</span><span style="color:#569cd6;">float</span><span style="color:#b4b4b4;">&gt;&gt;</span>&nbsp;<span style="color:#9cdcfe;">data</span><span style="color:#b4b4b4;">;</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">data</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">insert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">data</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">setosa</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">setosa</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">data</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">insert</span><span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">data</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">others</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">begin</span><span style="color:#b4b4b4;">(),</span>&nbsp;<span style="color:#9cdcfe;">others</span><span style="color:#b4b4b4;">.</span><span style="color:#dcdcaa;">end</span><span style="color:#b4b4b4;">()</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">network</span><span style="color:#b4b4b4;">.</span>test<span style="color:#b4b4b4;">(</span>&nbsp;<span style="color:#9cdcfe;">data</span>&nbsp;<span style="color:#b4b4b4;">);</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">network</span><span style="color:#b4b4b4;">.</span>show_network<span style="color:#b4b4b4;">();</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#9cdcfe;">network</span><span style="color:#b4b4b4;">.</span>show_output<span style="color:#b4b4b4;">();</span>
&nbsp;&nbsp;&nbsp;&nbsp;<span style="color:#d8a0df;">return</span>&nbsp;<span style="color:#b5cea8;">0</span><span style="color:#b4b4b4;">;</span>
<span style="color:#b4b4b4;">}</span></pre>
                            </td>
                        </tr>
                    </table>
            </td>
        </tr>
    </table>
    </div>
    </td></tr>
    </table>
</body>
</html>

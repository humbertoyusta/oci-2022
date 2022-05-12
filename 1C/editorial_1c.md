<h2>Subtarea 1</h2>

- $a_i = i$

En esta subtarea, $a_r - a_l = r - l$, por lo que siempre es posible ir de $i$ a cualquier $j \in [i+1, i + k]$ en 1 salto. Por tanto, la respuesta para una pregunta $(l, r)$ es $\left\lceil\frac{r - l}{k}\right\rceil$.

<h2>Subtarea 2</h2>

- $a_i - a_{i-1} = c$, para alguna constassnte $c$.

La idea es similar. En esta subtarea, $a_r - a_l = (r - l) \cdot c$.

Entonces, si queremos ir de $i$ a $j$ en un salto, se tiene que cumplir que

$(j - i)\cdot c \le k \iff (j - i) \le \left\lfloor\frac{k}{c}\right\rfloor$. Por tanto, podemos dar saltos de longitud $\left\lfloor\frac{k}{c}\right\rfloor$. 

Entonces, la respuesta para una pregunta $(l, r)$ es $\left\lceil\frac{r - l}{\left\lfloor\frac{k}{c}\right\rfloor}\right\rceil$.

<h2>Subtarea 3</h2>

 - $n\cdot q \le 10^6$.

Podemos resolver cada pregunta en tiempo lineal. Podemos usar dos punteros para dar los saltos óptimos, manteniendo para cada $l$, el mayor $r$ tal que $a_r - a_l \le k$.

Complejidad temporal: $\mathcal{O}(n\cdot q)$.
 
<h2>Subtarea 4</h2

Notemos que $k \ge \frac{a_n}{20}$, por lo que $\frac{a_n}{k} \le 20$. Eso quiere decir que la cantidad mínima de pasos para ir desde cualquier punto a otro es menor que o igual a 20. Por tanto, podemos usar la solución de la subtarea anterior.

<h2>Subtarea 5</h2>

Digamos que $f(l)$ es el mayor $r \ge l$ tal que $f(r) - f(l) \le k$. Si no existe tal $r$, digamos que $f(r) = -1$.

$f()$ se puede computar en tiempo lineal usando dos punteros, de derecha a izquierda. 

Podemos considerar esto como un grafo dirigido, donde cada nodo tiene grado de salida 1. De hecho, si consideramos los $x: f(x) = -1$ como raíces, este grafo es realmente un bosque con las aristas orientadas desde las hojas hacia la raíz.

Podemos usar la técnica **binary lifting**, que consiste en mantener para cada nodo, la lista de ancestros a distancia $2^0, 2^1, 2^2, 2^3, \dots$.

Si tenemos una pregunta $(l, r)$, usando esta lista de ancestros, podemos vorazmente buscar el primer ancestro de $l$ que sea mayor o igual que $r$, y la respuesta sería la diferencia entre las profundidades de $l$ y el ancestro encontrado en el grafo.
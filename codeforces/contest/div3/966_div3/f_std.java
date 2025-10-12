import java.io.*;
import java.util.*;

public class Main {
boolean MULTI_CASE = true;
boolean ALWAYS_FLUSH = false;

void go() {
    int n = nextInt();
    int tarScore = nextInt();
    int[][] a = new int[n][2];
    for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j < a[i].length; ++j) {
            a[i][j] = nextInt();
        }
    }
    int[][] c = new int[n][1];
    int BIG = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        c[i] = new int[a[i][0] + a[i][1] + 1];
        Arrays.fill(c[i], BIG);
        c[i][0] = 0;
        for (int j = 1; j < c[i].length; j++) {
            for (int k1 = 0; k1 <= a[i][0] && k1 <= j; k1++) {
                int k2 = j - k1;
                // k1 row, k2 col.
                c[i][j] = Math.min(c[i][j], k1 * a[i][1] + k2 * a[i][0] - k1 * k2);
            }
        }
    }
    int[] f = new int[tarScore + 1];
    Arrays.fill(f, BIG);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        int[] f2 = new int[tarScore + 1];
        Arrays.fill(f2, BIG);
        for (int j = 0; j < c[i].length; j++) {
            for (int k = 0; k < f.length; k++) {
                if (k + j > tarScore) break;
                if (f[k] >= BIG) continue;
                f2[k + j] = Math.min(f2[k + j], f[k] + c[i][j]);
            }
        }
        f = f2;
    }
    sl(f[tarScore] >= BIG ? -1 : f[tarScore]);
}

/**
 * Input.
 */
InputStream inStream;
byte[] inBuff = new byte[1024];
int inBuffCursor = 0, inBuffLen = 0;

boolean isVisibleChar(int c) {
    return 33 <= c && c <= 126;
}

boolean hasNextByte() {
    if (inBuffCursor < inBuffLen) return true;
    inBuffCursor = 0;
    try {
        inBuffLen = inStream.read(inBuff);
    } catch (Exception e) {
        e.printStackTrace(System.out);
    }
    return inBuffLen > 0;
}

boolean hasNext() {
    while (hasNextByte() && !isVisibleChar(inBuff[inBuffCursor])) inBuffCursor++;
    return hasNextByte();
}

int nextByte() {
    return hasNextByte() ? inBuff[inBuffCursor++] : -1;
}

String next() {
    if (!hasNext()) throw new RuntimeException("no next.");
    StringBuilder sb = new StringBuilder();
    int b = nextByte();
    while (isVisibleChar(b)) {
        sb.appendCodePoint(b);
        b = nextByte();
    }
    return sb.toString();
}

long nextLong() {
    if (!hasNext()) throw new RuntimeException("no next.");
    long result = 0;
    boolean negative = false;
    int b = nextByte();
    if (b < '0') {
        if (b == '-') negative = true;
        else if (b != '+') throw new RuntimeException("long number must start with +/-.");
        b = nextByte();
    }
    while (isVisibleChar(b)) {
        if (b < '0' || b > '9') throw new RuntimeException("wrong digit in long:" + (char) b);
        // NOTE: may overflow here, even if it is a valid Long, eg.-(1<<63).
        result = result * 10 + (b - '0');
        b = nextByte();
    }
    return negative ? -result : result;
}

int nextInt() {
    long x = nextLong();
    if (x < Integer.MIN_VALUE || x > Integer.MAX_VALUE)
        throw new RuntimeException("int overflow:" + x);
    return (int) x;
}

double nextDouble() {
    return Double.parseDouble(next());
}

/**
 * Output.
 */
PrintWriter printOut = new PrintWriter(System.out);

void so(Object obj, boolean newLine) {
    if (newLine) printOut.println(obj);
    else printOut.print(obj);
    if (ALWAYS_FLUSH) printOut.flush();
}

void so(Object obj) {
    so(obj, false);
}

void sl(Object obj) {
    so(obj, true);
}

void sl() {
    sl("");
}

/**
 * Main.
 */
void mainGo() {
    try {
        inStream = new FileInputStream("src/main.in");
        ALWAYS_FLUSH = true;
    } catch (Exception e) {
        inStream = System.in;
    }
    while (hasNext()) {
        if (MULTI_CASE) {
            int T = nextInt();
            if (T == 0) break;
            for (int i = 0; i < T; ++i) {
                go();
            }
        } else {
            go();
        }
    }
    printOut.flush();
}

public static void main(String[] args) throws Exception {
    new Main().mainGo();
}
}

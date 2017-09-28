/**
* @author Marcin Sztec
*    Swing version
*/
package zad8;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;

/**
* @author Marcin Sztec
*
*/
public class Main extends JFrame {
JButton go = new JButton("GET SITE");
JTextField jtf = new JTextField(30);
JTextArea codeArea = new JTextArea();
String url;
public Main() {

jtf.addCaretListener(new CaretListener() {
public void caretUpdate(CaretEvent ce) {
url = jtf.getText();
System.out.println("Text in real time: " + jtf.getText());
}
});

JPanel inputPanel = new JPanel(new BorderLayout(3, 3));
go.addActionListener(new ActionListener() {
public void actionPerformed(ActionEvent e) {
try {

URL pageURL = new URL(url);
System.out.println("url tekst: " +url);
HttpURLConnection urlConnection = (HttpURLConnection) pageURL.openConnection();
int respCode = urlConnection.getResponseCode();
String response = urlConnection.getResponseMessage();
codeArea.setText("HTTP/1.x " + respCode + " " + response + "\n");
int count = 1;
while (true) {
String header = urlConnection.getHeaderField(count);
String key = urlConnection.getHeaderFieldKey(count);
if (header == null || key == null) {
break;
}
codeArea.append(urlConnection.getHeaderFieldKey(count) + ": " + header + "\n");
count++;
}
InputStream in = new BufferedInputStream(urlConnection.getInputStream());
Reader r = new InputStreamReader(in);

int c;
while ((c = r.read()) != -1) {
codeArea.append(String.valueOf((char) c));
}
codeArea.setCaretPosition(1);
} catch (Exception ee) {
}
}
});
inputPanel.add(BorderLayout.EAST, go);
inputPanel.add(BorderLayout.WEST, jtf);

JScrollPane codeScroller = new JScrollPane(codeArea);
add(BorderLayout.NORTH, inputPanel);
add(BorderLayout.CENTER, codeScroller);
this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
this.setSize(700, 500);
this.setVisible(true);
}

public static void main(String[] args) {
JFrame webPageSourceViewer = new Main();
}
}
import java.awt.event.*;
import java.awt.*;
import java.awt.BorderLayout;
import javax.swing.*;

public class MainFrame extends JFrame{

    private static final long serialVersionUID = 1L;

    private Client client;
    private static JTextArea text;
    private JButton bsearch;
    private JButton bplay;
    private JButton bclose;

    public MainFrame(Client client){

        this.client = client;

        //setLocation(400,400);


        JPanel myPanel = new JPanel();
        add(myPanel);
        myPanel.setBackground(Color.blue);

        //Cree une zone de texte avec 20 lingnes et 30 colonnes
        text = new JTextArea(30, 40);

        // le retour a la ligne automatique
        //text.setLineWrap(true);


        JScrollPane scrollableTextArea = new JScrollPane(text);
        myPanel.add(scrollableTextArea, BorderLayout.CENTER);

        JPanel buttonPanel = new JPanel();
        myPanel.add(buttonPanel, BorderLayout.SOUTH);

        bsearch = new JButton("Search");
        buttonPanel.setBounds(400,100,300,150);
        buttonPanel.add(bsearch, BorderLayout.LINE_START);
        bsearch.addActionListener(new ButtonListener());

        bplay = new JButton("Play");
        buttonPanel.add(bplay, BorderLayout.CENTER);
        bplay.addActionListener(new ButtonListener());

        bclose = new JButton("Close");
        buttonPanel.add(bclose, BorderLayout.LINE_END);
        bclose.addActionListener(new ButtonListener());


         //cress menu bar
        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        JToolBar tools = new JToolBar();
        add(tools, BorderLayout.NORTH);

        Actions bsearch = new Actions("Search");
        menu.add(bsearch);
        tools.add(bsearch);

        Actions bplay = new Actions("Play");
        menu.add(bplay);
        tools.add(bplay);

        Actions bclose = new Actions("Close");
        menu.add(bclose);
        tools.add(bclose);


        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }


    private class ButtonListener implements ActionListener {

        public void actionPerformed(ActionEvent event){
            if (event.getSource()==bsearch){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name to search\n",
                    "Search",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){text.append(client.send("search "+s));}

            }
            else if (event.getSource()==bplay){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name to play\n",
                    "Play",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){text.append(client.send("play "+s));}
            }
            else if (event.getSource()==bclose){
                MainFrame.this.dispose();
            }

        }
    }

    private class Actions extends AbstractAction{

        private static final long serialVersionUID = 1L;

        private String name;

        public Actions(String name){
            super(name);
            //this.name  = name;
        }

        @Override
        public void actionPerformed(ActionEvent e) {

            try{
                if (name == "Search"){
                    String s = (String)JOptionPane.showInputDialog(
                        MainFrame.this,
                        "Enter the file name you want to search\n",
                        "Search",
                        JOptionPane.PLAIN_MESSAGE
                        );
                    if (s!=null){text.append(client.send("search "+s));}

                 }
                else if (name == "Play"){
                    String s = (String)JOptionPane.showInputDialog(
                        MainFrame.this,
                        "Enter the file name you want to play\n",
                        "Play",
                        JOptionPane.PLAIN_MESSAGE
                        );
                    if (s!=null){text.append(client.send("play "+s));}
                }
                else if (name == "Close"){
                    MainFrame.this.dispose();
                }
            }catch(Exception excep){System.out.println(excep);}
        }

    }

}

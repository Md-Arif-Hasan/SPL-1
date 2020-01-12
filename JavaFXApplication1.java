
package javafxapplication1;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;


public class JavaFXApplication1 extends Application {
    //private static Object layer1;
    //private static Object primaryStage;

    
    @Override
    public void start(Stage primaryStage) {
        Button btn = new Button();
        btn.setText("Hello World");
        
        Pane layer1 = new Pane();
        
        Button b1 = new Button("One ");
        b1.setLayoutX(100.0);
        b1.setLayoutY(45.0);
        
           btn.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Hello World!");
            }
        });
        
        StackPane root = new StackPane();
        root.getChildren().add(btn);
        
        TextField tf1 = new TextField();
        tf1.setLayoutX(100.0);
        tf1.setLayoutY(105.0);
        
        TextField tf2 = new TextField();
        tf2.setLayoutX(100.0);
        tf2.setLayoutY(285.0);
        
         TextField tf3 = new TextField();
        tf3.setLayoutX(15.0);
        tf3.setLayoutY(20.0);
        
        Text t1 = new Text("Md ");
        t1.setLayoutX(15.0);
        t1.setLayoutY(60.0);
        
          Text t2 = new Text("Arif");
        t2.setLayoutX(15.0);
        t2.setLayoutY(120.0);
        
          Text t3 = new Text("Hasan ");
        t3.setLayoutX(15.0);
        t3.setLayoutY(180.0);
        
          Text t4 = new Text("IIT");
        t4.setLayoutX(15.0);
        t4.setLayoutY(240.0);
        
          Text t5 = new Text("DU ");
        t5.setLayoutX(15.0);
        t5.setLayoutY(300.0);
        
          Text t6 = new Text("BSSE ");
        t6.setLayoutX(15.0);
        t6.setLayoutY(360.0);
        
        layer1.getChildren().addAll(b1,t1,t2,t3,t4,t5,t6);
        primaryStage.setScene(new Scene(layer1,320,450));
        primaryStage.show();
    }
    
    
     
    
    
    public static void main(String[] args) {
        launch(args);
        
        
}
}

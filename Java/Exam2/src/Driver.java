import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;
import java.util.Random;

import static javafx.application.Application.launch;

public class Driver extends Application
{
    // Menu bar is to tell the box that there is a menu area.

    private MenuBar menuBar;
    private TextArea textArea;
    public static void main(String[] args) { launch(args); }
    @Override
    public void start(Stage primaryStage)
    {
        BorderPane borderPane = new BorderPane();
        textArea = new TextArea();
        menuBar = new MenuBar();
        createThemeMenu();
        borderPane.setTop( menuBar);
        borderPane.setCenter( textArea);
        primaryStage.setScene( new Scene(borderPane));
        primaryStage.show();
    }


    private void createThemeMenu()
    {
        // Menu is the name of the clickables in the menu bar
        Menu menu = new Menu("Theme");
        Menu menuitem2 = new Menu("Exit");

        //
        menuBar.getMenus().addAll(menu,menuitem2);


        RadioMenuItem menuItem1 = new RadioMenuItem( "Dark");
        RadioMenuItem menuItem2 = new RadioMenuItem( "Light");
        menuItem2.setSelected( true);
        ToggleGroup toggleGroup = new ToggleGroup();
        menuItem1.setToggleGroup(toggleGroup);
        menuItem2.setToggleGroup(toggleGroup);
        menu.getItems().addAll(menuItem1, menuItem2);
        menuItem1.setOnAction(event -> {
            textArea.setStyle("-fx-control-inner-background: darkgray; -fx-text-fill: white; ");
        });
        menuItem2.setOnAction(event -> {
            textArea.setStyle("-fx-control-inner-background: white; -fx-text-fill: black; ");
        });
    }
}

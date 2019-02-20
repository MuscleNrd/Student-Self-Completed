/*
Homework #4
This assignment is a group project for groups of up to size 4. Due Friday, December 14th at 11:59pm
Your program should include a SubScene in which a user can add and edit Shape3D objects (only Spheres, Boxes, and Cylinders required).
A button at the bottom of the window titled "Add Shape" will open a form prompting the user to create a new Shape to add to the SubScene. The user should be asked for the required info (x, y) location, radius for spheres, width, height, and length for boxes, etc.
The user should also be allowed to change the background color of the subscene
When they click 'Submit', the shape should be added to the subscene.
On the right of the Screen should be a set of tools (sliders, textforms, dropdowns etc). These should perform transforms on the currently selected shape. When the user clicks a shape within the subscene, it becomes the selected shape. If we use the rotate control, only the selected shape should rotate. Users should be able to rotate, translate, scale, and change the color of a shape.
A menu system should be implemented allowing the user to save their current image. Determine a way to save the shapes in the subscene, as well as their locations and dimensions. The user can also open a valid file and the subscene should populate with the shapes specified by that file.
To be submitted: All source code files, as well as a brief report (~2 paragraphs) from each student discussing what challenges they encountered and how they were solved, as well as which part of the project they worked on.

 */

/*
 *  Steven Oseguera - scoseguera@cpp.edu
 *  Project: CS_2450_Final_Proj
 *  Driver.java - Created: December, 03, 2018 - 11:52 PM
 */

import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.effect.Light;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.*;
import javafx.scene.text.Text;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Translate;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import sun.plugin2.message.Serializer;

import javax.sound.midi.SysexMessage;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.security.Key;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.Vector;

public class Driver extends Application implements Serializable
{
	private static final long serialVersionUID = 1420672609912364060L;
	
	public static void main(String[] args)
	{
		launch(args);
	}
	
	private final int APPLICATION_HEIGHT = 768;
	private final int APPLICATION_WIDTH  = 1024;
	private final int SUBSCENE_HEIGHT    = 450;
	private final int SUBSCENE_WIDTH	 = 600;
	private final int MAX_WIDTH			 = 50;
	private final int MAX_HEIGHT		 = 50;
	private final int MAX_LENGTH		 = 50;
	private final int MAX_RADIUS		 = 50;
	private Point3D point 				 = new Point3D(0,0,0);
	
	private boolean INVALID_TEXT		 = true;
	
	private  Shape3D	shape_Focus			 = null;
	
	//** Shapes
	private Vector<Shape3D> myShapes	= new Vector<>();
	private Vector<MyShape> saveShapes  = new Vector<>();
	//////////////////////////////////////////////////////////////////////////////
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		//** Group Shape Stuff
		
		PerspectiveCamera pCamera = new PerspectiveCamera(true);
		Group shapesGroup = new Group();
		SubScene shapesSub = new SubScene(shapesGroup, SUBSCENE_WIDTH, SUBSCENE_HEIGHT,
				true, SceneAntialiasing. DISABLED);
			
		shapesSub.setOnMousePressed(MouseEvent ->
		{
			Iterator<Shape3D> it_Box = myShapes.iterator();
			
			if (myShapes.size() > 0)
				while(it_Box.hasNext())
				{
					Shape3D a = it_Box.next();
					if (a.isPressed())
					{
						shape_Focus = a;
						a.setOnMouseDragged(MouseEvent1 ->
						{
							a.getTransforms().add(new Translate(MouseEvent1.getX(),MouseEvent1.getY()));
						});
						return;
					}
				}
		});
		
		shapesSub.setCamera(pCamera);
		pCamera.getTransforms().addAll( new Translate(0, 0, -50));
		///////////////////////////////////////////////////////////////////////////
		
		
		// Change the SubScene’s background color
		shapesSub.setFill(Color.AQUA);
		///////////////////////////////////////////////////////////////////////////
		
		//** Buttons
		
		Button btn_addShape = new Button("Add Shape");
		Button btn_Submit   = new Button ("Submit");
		//////////////////////////////////////////////////////////////////////////////
		
		//** TextFields and Text
		
		Text txt_Rotate = new Text("Rotate");
		Text txt_Scale = new Text("Scale");
		
		Text txt_Location = new Text("Location");
		Text txt_Radius = new Text("Radius");
		Text txt_Width = new Text("Width");
		Text txt_Height = new Text("Height");
		Text txt_Length = new Text("Length");
		Text txt_Shape  = new Text("Shape");
		Text txt_Color = new Text("Color");
		
		TextField txtfld_Location = new TextField();
		txtfld_Location.setPromptText("Comma separated X,Y");
		
		TextField txtfld_Radius = 	new TextField();
		txtfld_Radius.setPromptText("Radius Max: " + String.valueOf(MAX_RADIUS));
		
		TextField txtfld_Width  = 	new TextField();
		txtfld_Width.setPromptText("Width Max: " + String.valueOf(MAX_WIDTH));
		
		TextField txtfld_Height  = 	new TextField();
		txtfld_Height.setPromptText("Height Max: " + String.valueOf(MAX_HEIGHT));
		
		TextField txtfld_Length = new TextField();
		txtfld_Length.setPromptText("Length Max: " + String.valueOf(MAX_LENGTH));
		
		txtfld_Location.setOnKeyReleased(KeyEvent->
		{
			String[] temp = txtfld_Location.getText().split(",");
			
			if (temp.length >= 3)
			{
				txtfld_Location.setStyle("-fx-text-inner-color: red;");
				txtfld_Location.setText("Invalid Syntax: x,y");
			}
			if (temp.length >= 2)
			{
				try
				{
					this.point = new Point3D(Float.parseFloat(temp[0]),Float.parseFloat(temp[1]),0);
				}
				catch (Exception e)
				{
					txtfld_Location.setStyle("-fx-text-inner-color: red;");
					txtfld_Location.setText("Invalid Syntax: x,y");
					return;
				}
				
			}
			else
			{
				txtfld_Location.setStyle("-fx-text-inner-color: black;");
			}
		
		});
		///////////////////////////////////////////////////////////////////////////

		//** Sliders
		Slider slider_Rotate_Veritcal = new Slider(0,100, 0);
		slider_Rotate_Veritcal.setShowTickMarks(true);
		slider_Rotate_Veritcal.setShowTickLabels(true);
		slider_Rotate_Veritcal.setMajorTickUnit(50);
		slider_Rotate_Veritcal.setOrientation(Orientation.VERTICAL);
		
		slider_Rotate_Veritcal.setOnMouseReleased(MouseEvent ->
		{
			
			if (shape_Focus != null)
			{
				shape_Focus.setLayoutY(0);
				shape_Focus.getTransforms().add(new Rotate(slider_Rotate_Veritcal.getValue()/100 * 180, Rotate.Y_AXIS));
			}
			
		});

		Slider slider_Rotate_Horizontal = new Slider(0,100, 0);
		slider_Rotate_Horizontal.setShowTickMarks(true);
		slider_Rotate_Horizontal.setShowTickLabels(true);
		slider_Rotate_Horizontal.setMajorTickUnit(50);
		slider_Rotate_Horizontal.setOnMouseReleased(MouseEvent ->
		{
			if (shape_Focus != null)
			{
				shape_Focus.setLayoutY(0);
				shape_Focus.getTransforms().add(new Rotate(slider_Rotate_Horizontal.getValue()/100 * 180, Rotate.X_AXIS));
			}
		});

		Slider slider_Scale = new Slider (0, 10, 0);
		slider_Scale.setShowTickMarks(true);
		slider_Scale.setShowTickLabels(true);
		slider_Scale.setMajorTickUnit(1);
		
		slider_Scale.setOnMouseReleased(MouseEvent ->
		{
			if (shape_Focus != null)
			{
				shape_Focus.setScaleX(slider_Scale.getValue());
				shape_Focus.setScaleY(slider_Scale.getValue());
				
			}
		});
		///////////////////////////////////////////////////////////////////////////


		//** Combo Boxes  https://docs.oracle.com/javafx/2/ui_controls/combo-box.htm

		ObservableList<String> Shapes = FXCollections.observableArrayList("Box","Cylinder","Sphere");
		ObservableList<String> Colors = FXCollections.observableArrayList("None","Red","Blue","Green","Purple","Yellow");

		final ComboBox<String> cbox_Shape = new ComboBox<>(Shapes);
		final ComboBox<String> cbox_Color = new ComboBox<>(Colors);
		
		cbox_Shape.getSelectionModel().select(0);
		cbox_Color.getSelectionModel().select(0);
		
		cbox_Shape.setOnAction(event ->
		{
			switch (cbox_Shape.getSelectionModel().getSelectedItem())
			{
				case "Box":
				{
					txt_Height.setVisible(true);
					txt_Length.setVisible(true);
					txt_Width.setVisible(true);
					txtfld_Height.setVisible(true);
					txtfld_Length.setVisible(true);
					txtfld_Width.setVisible(true);
					
					txt_Radius.setVisible(false);
					txtfld_Radius.setVisible(false);
					break;
				}
				case "Cylinder":
				{
					txt_Height.setVisible(true);
					txt_Length.setVisible(false);
					txt_Width.setVisible(false);
					txtfld_Height.setVisible(true);
					txtfld_Length.setVisible(false);
					txtfld_Width.setVisible(false);
					
					txt_Radius.setVisible(true);
					txtfld_Radius.setVisible(true);
					break;
				}
				case "Sphere":
				{
					txt_Height.setVisible(false);
					txt_Length.setVisible(false);
					txt_Width.setVisible(false);
					txtfld_Height.setVisible(false);
					txtfld_Length.setVisible(false);
					txtfld_Width.setVisible(false);
					
					txt_Radius.setVisible(true);
					txtfld_Radius.setVisible(true);
					break;
				}
				
			}
		});
		
		cbox_Color.setOnAction(event ->
		{
			if (shape_Focus != null)
			{
				switch(cbox_Color.getSelectionModel().getSelectedItem())
				{
					case "None":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.GRAY));
						break;
					}
					case "Red":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.RED));
						break;
					}
					case "Blue":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.BLUE));
						break;
					}
					case "Yellow":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.YELLOW));
						break;
					}
					case "Green":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.GREEN));
						break;
					}
					case "Purple":
					{
						shape_Focus.setMaterial(new PhongMaterial(Color.PURPLE));
						break;
					}
				}
			}
			
		});

		///////////////////////////////////////////////////////////////////////////
		//** Menu Bar
		MenuBar menubar = new MenuBar();
		Menu menu_File = new Menu("File");
		MenuItem Save = new MenuItem("Save");
		MenuItem Load = new MenuItem  ("Load");
		menubar.getMenus().add(menu_File);
		menu_File.getItems().addAll(Save,Load);
		
		BorderPane root_borderPane = new BorderPane ();
		
		root_borderPane.setTop(menubar);
		///////////////////////////////////////////////////////////////////////////
		
		//** Extra Panes
		
		GridPane gridpn_right_Options = new GridPane();
		gridpn_right_Options.setAlignment(Pos.CENTER);
		gridpn_right_Options.setPadding(new Insets(100));
		
		gridpn_right_Options.add(txt_Rotate,0,0);
		gridpn_right_Options.add(slider_Rotate_Veritcal,0,1);
		gridpn_right_Options.add(slider_Rotate_Horizontal,0,2);
		
		gridpn_right_Options.add(txt_Scale,1,0);
		gridpn_right_Options.add(slider_Scale,1,1);
		gridpn_right_Options.add(txt_Color, 1,3);
		gridpn_right_Options.add(cbox_Color,1,4);
		
		root_borderPane.setRight(gridpn_right_Options);
		
		GridPane gridpn_bottom_Options = new GridPane();
		gridpn_bottom_Options.setPadding(new Insets(10));
		gridpn_bottom_Options.setAlignment(Pos.CENTER);
		
		
		gridpn_bottom_Options.add(txt_Shape,0,0);
		gridpn_bottom_Options.add(cbox_Shape, 0, 1);
		
		gridpn_bottom_Options.add(btn_Submit,1,1);
		
		gridpn_bottom_Options.add(txt_Location, 0, 2);
		gridpn_bottom_Options.add(txtfld_Location,0,3);
		
		gridpn_bottom_Options.add(txt_Width,1,2);
		gridpn_bottom_Options.add(txtfld_Width,1,3);
		
		gridpn_bottom_Options.add(txt_Radius,0,4);
		gridpn_bottom_Options.add(txtfld_Radius,0,5);
		
		gridpn_bottom_Options.add(txt_Height,1,4);
		gridpn_bottom_Options.add(txtfld_Height,1,5);
		
		gridpn_bottom_Options.add(txt_Length,1,6);
		gridpn_bottom_Options.add(txtfld_Length,1,7);
		///////////////////////////////////////////////////////////////////////////
		
		btn_addShape.setOnAction(event ->
		{
			root_borderPane.setBottom(gridpn_bottom_Options);
		});
		
		btn_Submit.setOnAction(event ->
		{
			if (INVALID_TEXT)
			{
				createPopUp("Error","Text Box Issue","Please correct red areas!", Alert.AlertType.ERROR);
				return;
			}
			
			// TODO: 12/10/2018  Create shape
			// Create Shape function:
			
			switch (cbox_Shape.getSelectionModel().getSelectedItem())
			{
				case "Box":
				{
					myShapes.add(new Box(Integer.parseInt(txtfld_Length.getText()), Integer.parseInt(txtfld_Width.getText()), Integer.parseInt(txtfld_Height.getText())));
					myShapes.elementAt(myShapes.size() - 1).getTransforms().add(new Translate(this.point.getX(),this.point.getY(),0));
					shapesGroup.getChildren().add(myShapes.elementAt(myShapes.size() - 1));
					break;
				}
				case "Cylinder":
				{
					myShapes.add(new Cylinder(Integer.parseInt(txtfld_Radius.getText()), Integer.parseInt(txtfld_Height.getText())));
					myShapes.elementAt(myShapes.size() - 1).getTransforms().add(new Translate(this.point.getX(),this.point.getY(),0));
					shapesGroup.getChildren().add(myShapes.elementAt(myShapes.size() - 1));
					break;
				}
				case "Sphere":
				{
					myShapes.add(new Sphere(Integer.parseInt(txtfld_Radius.getText())));
					myShapes.elementAt(myShapes.size() - 1).getTransforms().add(new Translate(this.point.getX(),this.point.getY(),0));
					shapesGroup.getChildren().add(myShapes.elementAt(myShapes.size() -1 ));
					break;
				}
			}
			
			/////////////////////////////////////////////////////////////////////////////
			
			// Reset to Add Shape button
			HBox hbox = new HBox(btn_addShape);
			hbox.setAlignment(Pos.CENTER);
			root_borderPane.setBottom(hbox);
		});
		
		txt_Radius.setVisible(false);
		txtfld_Radius.setVisible(false);
		
		root_borderPane.setCenter(shapesSub);
		
		txtfld_Width.addEventHandler(KeyEvent.KEY_RELEASED,new validateInput().init(txtfld_Width,MAX_WIDTH));
		txtfld_Radius.addEventHandler(KeyEvent.KEY_RELEASED,new validateInput().init(txtfld_Radius,MAX_RADIUS));
		txtfld_Height.addEventHandler(KeyEvent.KEY_RELEASED,new validateInput().init(txtfld_Height,MAX_HEIGHT));
		txtfld_Length.addEventHandler(KeyEvent.KEY_RELEASED,new validateInput().init(txtfld_Length, MAX_LENGTH));
		
		HBox temp = new HBox(btn_addShape);
		temp.setAlignment(Pos.CENTER);
		root_borderPane.setBottom(temp);
		
		Scene scene = new Scene(root_borderPane,APPLICATION_WIDTH,APPLICATION_HEIGHT);
		
		Save.setOnAction(event ->
		{
			FileChooser fileChooser = new FileChooser();
			fileChooser.setTitle("Save Image");
			
			File file = fileChooser.showSaveDialog(primaryStage);
			if (file != null)
			{
				try
				{
					FileOutputStream fis = new FileOutputStream(new File(file.getPath()));
					ObjectOutputStream oos = new ObjectOutputStream(fis);
					
					oos.writeObject(myShapes);
					
					fis.close();
					oos.close();
					
					
				}
				catch (Exception x)
				{
					System.out.println(x);
					return;
				}
				
			}
		});
		
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	
	
	private class validateInput implements EventHandler<KeyEvent>
	{
		private TextField textfield;
		private int MAX_NUM;
		private boolean cleared = false;
		
		@Override
		public void handle(KeyEvent event)
		{
			
			if (!event.getCode().isDigitKey())
			{
				this.textfield.setText("Digits Only!");
				this.textfield.setStyle("-fx-text-inner-color: red;");
				INVALID_TEXT = true;
				cleared = false;
			}
			else if (!cleared)
			{
				Character temp = this.textfield.getText().charAt(0);
				this.textfield.setStyle("-fx-text-inner-color: black;");
				this.textfield.clear();
				this.textfield.setText(temp.toString());
				this.textfield.positionCaret(1);
				INVALID_TEXT = false;
				cleared = true;
			}
			
			else if (Integer.parseInt(this.textfield.getText()) > MAX_NUM)
			{
				this.textfield.setText("MAX: " + MAX_NUM);
				this.textfield.setStyle("-fx-text-inner-color: red;");
				INVALID_TEXT = true;
				cleared = false;
			}
			
			System.out.println(this.textfield.getText());
		}
		
		public validateInput init(TextField textfield, int MAX_NUM)
		{
			this.textfield = textfield;
			this.MAX_NUM = MAX_NUM;
			return this;
		}
		
	}
	
	private void createPopUp(String Title, String HeaderText, String ContextText, Alert.AlertType alertType)
	{
		Alert alert = new Alert(alertType);
		alert.setTitle(Title);
		alert.setHeaderText(HeaderText);
		alert.setContentText(ContextText);
		alert.showAndWait();
	}
	
	private class MyShape implements Serializable
	{
		final int BOX = 1;
		final int CYLINDER = 2;
		final int SPHERE = 3;
		
		int type = 0;
		double width = 0;
		double height = 0;
		double depth = 0;
		double rotation = 0;
		double scaleX = 0;
		double scaleY = 0;
		double scaleZ = 0;
		double radius = 0;
		double locationX = 0;
		double locationY = 0;
		
		public MyShape(Box box)
		{
			this.type = BOX;
			
			this.width = box.getWidth();
			this.height = box.getHeight();
			this.depth = box.getDepth();
			this.rotation = box.getRotate();
			this.scaleX = box.getScaleX();
			this.scaleY = box.getScaleY();
			this.scaleZ = box.getScaleZ();
			this.locationX = box.getLayoutX();
			this.locationY = box.getLayoutY();
		}
		
		public MyShape(Sphere sphere)
		{
			this.type = SPHERE;

			this.radius	  = sphere.getRadius();
			this.rotation = sphere.getRotate();
			this.scaleX = sphere.getScaleX();
			this.scaleY = sphere.getScaleY();
			this.scaleZ = sphere.getScaleZ();
			this.locationX = sphere.getLayoutX();
			this.locationY = sphere.getLayoutY();
			
		}
		
		public MyShape(Cylinder cylinder)
		{
			this.type = CYLINDER;
			
			this.radius = cylinder.getRadius();
			this.rotation = cylinder.getRotate();
			this.scaleX = cylinder.getScaleX();
			this.scaleY = cylinder.getScaleY();
			this.scaleZ = cylinder.getScaleZ();
			this.locationX = cylinder.getLayoutX();
			this.locationY = cylinder.getLayoutY();
		}
	}
}
